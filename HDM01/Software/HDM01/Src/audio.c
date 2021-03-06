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
//					This application uses DMA to fill the circular buffer
//
//					Circular Buffer Capacity:
//						16-bit audio:	8 samples L, R
//						24-bit audio:   4 samples L, R (padding is introduced)
//
//		* Dolby is a registered trademark of Dolby Labs - mentioned for reference only!
//
//-----------------------------------------------------------------------------------------------------------------------------------------

// Includes
#include "audio.h"
#include "stm32f0xx_rcc.h"					// For STM32F0xx micros
#include "level.h"

#define SPI1_DR_Address SPI1_BASE + 0x0C	// Uses definition in stm32f0xx.h


unsigned char WORD_SIZE;					// System variable indicating word size
uint16_t AUDIO_CIRC_BUFFER[16];				// Circular buffer for audio samples
uint32_t LEFT_METER_PCM;					// 16 ~ 24 bit sample for metering - LEFT CHANNEL
uint32_t RIGHT_METER_PCM;					// 16 ~ 24 bit sample for metering - RIGHT CHANNEL

// Structs access

GPIO_InitTypeDef GPIO_InitStructure;		// GPIO init struct
I2S_InitTypeDef I2S_InitStructure;			// Initialisation struct (SPI in I2S mode)
NVIC_InitTypeDef NVIC_InitStructure;
DMA_InitTypeDef DMA_InitStructure;			// Init struct for DMA controller

// Name: ClearAudioBuffer
// Function: Fill the audio buffer with zeroes
//---------------------------------------------
void ClearAudioBuffer(void){
	unsigned int c;

	for (c = 0; c < 16; c++){
		AUDIO_CIRC_BUFFER[c] = 0;
	}

}

// Name: SetWordSize
// Function: Set the word size to match the incoming digital stream
//           This function is called from the code managing the DIR
//           and then sets the word size as soon as the DIR is able to detect the incoming S/PDIF stream
// Parameters: Word Size, caller MUST set to zero if the DIR cannot lock onto the S/PDIF
// Returns: void
//-------------------------------------------------------------------------------------------------------
void SetWordSize(unsigned char WS){

	WORD_SIZE = WS;

}

unsigned char GetWordSize(void){
	return WORD_SIZE;
}

// Name: GetSamples
// Function: Retrieve metering samples
// Parameters: variables for storage of left and right samples
// Returns: void
//-------------------------------------------------------------------------------------------
void GetSamples(uint32_t *LEFT, uint32_t *RIGHT){

	*LEFT = LEFT_METER_PCM;
	*RIGHT = RIGHT_METER_PCM;

}

//------------------------------------------------------------------------------------------
// Name: InitAudioIF
// Function: Initialize the digital audio interface subsystem
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------------------
void InitAudioIF(void){

	WORD_SIZE = 0;
	ClearAudioBuffer();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);				// Enable Clock to SPI1
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);					// Enable clock to DMA1

	// PA4 thru PA7 assigned as alternate functions (SPI1)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// PA4 thru PA7 connected to the peripheral (SPI1), PA6 is unassigned as we don't use the MCLK (we're not an oversampling DAC)
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_0);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_0);


	// Set up SPI1 - DIR facing (slave - clocked from digital audio source)
	I2S_InitStructure.I2S_Standard = I2S_Standard_Phillips;
	I2S_InitStructure.I2S_DataFormat = I2S_DataFormat_24b;								// << this here will change according to what we get from the source
	I2S_InitStructure.I2S_MCLKOutput = I2S_MCLKOutput_Disable;							// Slave requires MCLK to be off
	I2S_InitStructure.I2S_AudioFreq = I2S_AudioFreq_48k;								// << this here again will depend on the source
	I2S_InitStructure.I2S_CPOL = I2S_CPOL_Low;											// Clock polarity
	I2S_InitStructure.I2S_Mode = I2S_Mode_SlaveRx;										// Slave Mode
	I2S_Init(SPI1, &I2S_InitStructure);													// Configure the module


	// Configure the DMA controller for this peripheral - Channel 2
	DMA_InitStructure.DMA_BufferSize = 16;												// 16 word buffer size
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;			// Set to match the peripheral (16 bits)
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;					// Set to match destination memory (16 bits)
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;					// Address at src remains static
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;								// Address at dest is auto-increment
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;										// Circular buffer
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;										// Non memory-to-memory transfer
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)SPI1_DR_Address;				// Source address
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)AUDIO_CIRC_BUFFER;					// Destination address (BEWARE of cast)!
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;									// Peripheral -> Memory transfer direction
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;									// High priority transfer
	DMA_Init(DMA1_Channel2, &DMA_InitStructure);										// Load the configuration

	DMA_ITConfig(DMA1_Channel2, DMA_IT_TC, ENABLE);										// Enable DMA Terminal Count interrupt!
	DMA_Cmd(DMA1_Channel2, ENABLE);														// Enable the DMA channel
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);									// DMA is enabled!

	I2S_Cmd(SPI1, ENABLE);

	// Enable DMA interupt
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}




//--------------------------------------------------------------------------------------------------------
// DMA interrupt-
// This interrupt is raised every time the buffer reaches the start point i.e. just before the old
// samples are over-written with new ones
//--------------------------------------------------------------------------------------------------------
void DMA1_Channel2_3_IRQHandler(void){
	uint32_t TMP = 0;

	WORD_SIZE = AUDIO_24_BITS;			// << FOR DEBUGGING

	if (DMA_GetITStatus(DMA1_IT_TC2)== SET){
		DMA_ClearITPendingBit(DMA1_IT_TC2);				// Clear Interrupt flag

		// Process sampling from the buffer according to setup

		if(WORD_SIZE == AUDIO_16_BITS){
			LEFT_METER_PCM = AUDIO_CIRC_BUFFER[0];
			RIGHT_METER_PCM = AUDIO_CIRC_BUFFER[1];
		}

		if(WORD_SIZE == AUDIO_24_BITS){
			*(((uint16_t *)&TMP) + 1) = AUDIO_CIRC_BUFFER[0];
			*(((uint16_t *)&TMP) + 0) = AUDIO_CIRC_BUFFER[1];
			TMP >>= 8;												// right-justify the PCM value
			LEFT_METER_PCM = TMP;									// left channel meter stored

			*(((uint16_t *)&TMP) + 1) = AUDIO_CIRC_BUFFER[2];
			*(((uint16_t *)&TMP) + 0) = AUDIO_CIRC_BUFFER[3];
			TMP >>= 8;												// right-justify the PCM value
			RIGHT_METER_PCM = TMP;									// right channel meter stored

		}

		// Do call to metering code so that it is aware there's a sample
		UpdateCall();

	}

}


