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
//					FILENAME: level.c
//					Purpose: PPM / VU level metering from 16-24 bit PCM digita audio
//					Dependencies:
//						1. Math libraries
//						2. Timer Tick
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

// Includes
//---------------
#include "level.h"
#include "stm32f0xx_rcc.h"					// For STM32F0xx micros
#include "audio.h"
#include <math.h>

// Variables
uint32_t	LEFT_PCM;
uint32_t	RIGHT_PCM;
float		LEFT_CHANNEL;
float		RIGHT_CHANNEL;

unsigned char UPDATE_PENDING;

GPIO_InitTypeDef GPIO_InitStructure;		// GPIO init struct

#define ATTACK exp(log(0.01)/ 20 * 48000 * 0.01)
#define DECAY exp(log(0.01)/ 1000 * 48000 * 0.01)

// Name: InitLevel
// Function: Initialize the level meter
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------------
void InitMeter(void){

	UPDATE_PENDING = 0;
	// Temporary assignments - LED VU meter for debugging..
	GPIO_InitStructure.GPIO_Pin = LD1 | LD2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
//
	GPIO_InitStructure.GPIO_Pin = LD3 | LD4 | LD5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

}


// Name: ServiceMeter
// Function: Services the LED meter, called every 1ms
// Parameters: void
// Returns: void
//----------------------------------------------
void ServiceMeter(void){

	if(UPDATE_PENDING == 1){
		UPDATE_PENDING = 0;
		if(GetWordSize() == AUDIO_16_BITS){


		}
		if(GetWordSize() == AUDIO_24_BITS){

			LEFT_CHANNEL = LEFT_PCM / 8388608;		// Conversion to +1 .. -1 floating point format
			RIGHT_CHANNEL = RIGHT_PCM / 8388608;		// Conversion to +1 .. -1 floating point format    -- DSP 101


		}
	}
/*	if(DIG_AUDIO_SAMPLE > PREV_ENVELOPE){
		ENVELOPE = DIG_AUDIO_SAMPLE;				// Incoming sample larger than history... update
	} else {
		// incoming level is less, we begin to taper down the display
		if (ENVELOPE > 0xB3FF){
			ENVELOPE = ENVELOPE - 0x3000;
		}
	}
	DIG_AUDIO_SAMPLE = 0;
	PREV_ENVELOPE = ENVELOPE;
	// Update LED display with the envelope
	//GPIO_ResetBits(GPIOC, LD1);
	//GPIO_ResetBits(GPIOC, LD2);
	//GPIO_ResetBits(GPIOB, LD3);
	//GPIO_ResetBits(GPIOB, LD4);
	//GPIO_ResetBits(GPIOB, LD5);			// display cleared

	// Turn off points
	if(ENVELOPE < 0xB400){
		GPIO_ResetBits(GPIOC, LD1);
	}

	if(ENVELOPE < 0x022000){
		GPIO_ResetBits(GPIOC, LD2);
	}

	if(ENVELOPE < 0x091000){
		GPIO_ResetBits(GPIOB, LD3);
	}

	if(ENVELOPE < 0x110000){
		GPIO_ResetBits(GPIOB, LD4);
	}

	if(ENVELOPE < 0x600000){
		GPIO_ResetBits(GPIOB, LD5);
	}

	// Turn on points
	if(ENVELOPE > 0xc600){
		GPIO_SetBits(GPIOC, LD1);		// LED1 on -40dB or greater
	}

	if(ENVELOPE > 0x030000){
		GPIO_SetBits(GPIOC, LD2);
	}

	if(ENVELOPE > 0x0A0000){
		GPIO_SetBits(GPIOB, LD3);
	}

	if(ENVELOPE > 0x150000){
		GPIO_SetBits(GPIOB, LD4);
	}

	if(ENVELOPE > 0x640000){
		GPIO_SetBits(GPIOB, LD5);
	} */
}

//-----------------------------------------------------------------------
// Name: UpdateCall
// Function: Signaling from the digital audio processor
//           This is called to let us know there's PCM to process
// Parameters: void
// Returns: void
//-----------------------------------------------------------------------
void UpdateCall(void){

	GetSamples(&LEFT_PCM, &RIGHT_PCM);
	UPDATE_PENDING = 1;
}



