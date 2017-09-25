//----------------------------------------------------------------------------------------------------------------------------------
//
//							Author: Sonikku
//
//                              ______
//	                      _.-*'"      "`*-._
//	                _.-*'                  `*-._
//	             .-'                            `-.
//	  /`-.    .-'                  _.              `-.
//	 :    `..'                  .-'_ .                `.
//	 |    .'                 .-'_.' \ .                 \
//	 |   /                 .' .*     ;               .-'"
//	 :   L                    `.     | ;          .-'
//	  \.' `*.          .-*"*-.  `.   ; |        .'
//	  /      \        '       `.  `-'  ;      .'
//	 : .'"`.  .       .-*'`*-.  \     .      (_
//	 |              .'        \  .             `*-.
//	 |.     .      /           ;                   `-.
//	 :    db      '       d$b  |                      `-.
//	 .   :PT;.   '       :P"T; :                         `.
//	 :   :bd;   '        :b_d; :                           \
//	 |   :$$; `'         :$$$; |                            \
//	 |    TP              T$P  '                             ;
//	 :                        /.-*'"`.                       |
//	.sdP^T$bs.               /'       \
//	$$$._.$$$$b.--._      _.'   .--.   ;
//	`*$$$$$$P*'     `*--*'     '  / \  :
//	   \                        .'   ; ;
//	    `.                  _.-'    ' /
//	      `*-.                      .'
//	          `*-._            _.-*'
//	               `*=--..--=*'
//
//
//					FILENAME: audio.c
//					Purpose: Digital audio processing on the STM32F0
//					Dependencies:
//						1. One of the SPI modules in I2S mode
//						2. Digital Interface Receiver (PCM9210/9211)
//						4. DMA features on the STM32F0
//
//					Supported word size: 	16 bit, 24 bit
//					Supported Sampling rates: 44.1, 48, 96, 192 kHz
//
//					NOTE: This implementation does not know about the sampling rate ahead of time, therefore
//                        the code is designed to operate with the PCM9210/9211 library to use hardware
//                        features of the PCM9210/9211 to obtain the sampling rate, validity (i.e. ignore Dolby Digital/DTS) and word size
//
//
//					This design detects the presence of compressed (Dolby/DTS/MPEG) streams and mutes the output accordingly to prevent
//                  damage to headphones and ears!
//
//		* Dolby is a registered trademark of Dolby Labs - mentioned for reference only!
//
//-----------------------------------------------------------------------------------------------------------------------------------------

// Includes
#include "audio.h"
#include "stm32f0xx_rcc.h"					// For STM32F0xx micros

//uint32_t AUDIO_BUFFER[64];					// Audio buffer (64 32-bit words) 32 left samples, 32 right samples

unsigned char left_toggle;
unsigned char right_toggle;
uint16_t R1;
uint16_t R2;
uint16_t L1;
uint16_t L2;

// Structs access
SPI_InitTypeDef	SPI_InitStructure;			// Initialisation struct
GPIO_InitTypeDef GPIO_InitStructure;		// GPIO init struct
I2S_InitTypeDef I2S_InitStructure;			// Initialisation struct (SPI in I2S mode)
NVIC_InitTypeDef NVIC_InitStructure;

//------------------------------------------------------------------------------------------
// Name: InitAudioIF
// Function: Initialize the digital audio interface subsystem
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------------------
void InitAudioIF(void){

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);				// Enable Clock to SPI1

	// PA4 thru PA7 assigned as alternate functions (SPI1)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// PA4 thru PA7 connected to the peripheral (SPI1)
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_0);


	// Set up SPI1 - DIR facing (slave - clocked from digital audio source)
	I2S_InitStructure.I2S_Standard = I2S_Standard_Phillips;
	I2S_InitStructure.I2S_DataFormat = I2S_DataFormat_24b;			// << this here will change according to what we get from the source
	I2S_InitStructure.I2S_MCLKOutput = I2S_MCLKOutput_Disable;		// Slave requires MCLK to be off
	I2S_InitStructure.I2S_AudioFreq = I2S_AudioFreq_48k;			// << this here again will depend on the source
	I2S_InitStructure.I2S_CPOL = I2S_CPOL_Low;						// Clock polarity
	I2S_InitStructure.I2S_Mode = I2S_Mode_SlaveRx;					// Slave Mode
	I2S_Init(SPI1, &I2S_InitStructure);								// Configure the module



	// Configure interrupts on SPI1
	NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// Enable interrupts on SPI1, typically receive interrupt
//	SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_RXNE, ENABLE);      << disabled for now as it loads the CPU badly, causing display tearing


	// Enable it
	I2S_Cmd(SPI1, ENABLE);
}


// Receive interrupt vector
//-------------------------
void SPI1_IRQHandler(void){

	// Check for errors
	if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_FRE)){

		// Frame error, sample is invalid
		R1 = 0;
		R2 = 0;
		L1 = 0;
		L2 = 0;

	}


	if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE)){
		// We have an audio sample (16 - 24 bits), for now we assume 24 bits (will fix later)
		if(SPI_I2S_GetFlagStatus(SPI1, I2S_FLAG_CHSIDE)){
			// Right channel received
			R1 = SPI1->DR;			// bits 23 - 16
			R2 = SPI1->DR;			// bits 15 - 0

		} else {
			// Left channel received
			L1 = SPI1->DR;
			L2 = SPI1->DR;

		}
	}

}
