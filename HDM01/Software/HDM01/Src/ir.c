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
//					FILENAME: ir.c
//					Purpose: Infra-red remote control decoder library
//					Dependencies:
//						1. A Timer with Capture/Compare functions
//							This timer should be clocked at 1uS to get the resolution for measuring pulses
//						2. A system ticker generating events every 1mS
//						3. The ability to read the level of the TIM channel pin even though its a CCx input
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

// Includes
//---------------

#include "ir.h"
#include "stm32f0xx_rcc.h"			// For STM32F0xx micros
#include <stdio.h>
#include <string.h>
#include "serial.h"

// Definitions, constants etc
//------------------------------------
#define START_PULSE_MIN		7800					// NEC protocol minimum start pulse width
#define START_PULSE_MAX		9500					// NEC protocol maximum start pulse width
#define QUIET_MIN 3800
#define QUIET_MAX 4700


TIM_ICInitTypeDef  TIM_ICInitStructure;				// Input capture registers struct
GPIO_InitTypeDef GPIO_InitStructure;				// GPIO struct
NVIC_InitTypeDef NVIC_InitStructure;				// Interrupt Controller struct

char dbgstr[32];
unsigned char T1;
unsigned char data_toggle;
unsigned char bitcount;
uint32_t CAPTURE;
uint32_t IR_DATA;
uint32_t PULSETIME;
uint16_t ADDRESS;
uint16_t COMMAND;
unsigned char IR_TIMER;
unsigned char IR_EVENT;


//-------------------------------------------------------------------------------------------
// Name: InitIR
// Function: Initialises the timer used, and the interrupt for the IR receiver
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------------------
void InitIR(void){

	// Enable clock to TIM1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	// TIM1_CH2 pin is an AF2 on PA9
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// For debug- Set up PA10 for the oscilloscope
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOA, GPIO_Pin_10);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_2);

	// Enable interrupt TIM1
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);


	// Input Capture setup...
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_BothEdge;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICFilter = 0x0;
	TIM_ICInit(TIM1, &TIM_ICInitStructure);

	// Enable the TIM1
	TIM_PrescalerConfig(TIM1, 48, TIM_PSCReloadMode_Immediate);
	TIM_Cmd(TIM1, ENABLE);
	TIM_ITConfig(TIM1, TIM_IT_CC2, ENABLE);
	T1 = 0;
	IR_TIMER = 0;
	ADDRESS = 0;
	COMMAND = 0;
	IR_DATA = 0;
	IR_EVENT = 0;

}


//-----------------------------------------------------------------------------------------
// Name: IR_IRQ_HNDL
// Interrupt Handler for input pulses (falling edge)
//----------------------------------------------------------------------------------------
void IR_IRQ_HNDL(void){

    TIM_ClearITPendingBit(TIM1, TIM_IT_CC2);		// Clear IRQ
    CAPTURE = TIM_GetCapture2(TIM1);				// Grab the captured value
    TIM_SetCounter(TIM1, 0);						// Clear the timer

    switch(T1){

    // Initial state - captured first edge of the incoming stream
    case 0:
    	CAPTURE = 0;											// Reset CAPTURE value
    	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0){
    		T1 = 1;												// Falling edge we can go to the next state
    	}
    	break;

    // Start pulse is measured
    case 1:
    	//dbgstr[0] = 0;
    	//sprintf(dbgstr, "\r\n CAPTURE VALUE ON START PULSE: %d", CAPTURE);
    	//TxData(dbgstr);
    	if (CAPTURE > START_PULSE_MIN && CAPTURE < START_PULSE_MAX){
    		T1 = 2;
    	} else {
    		T1 = 0;
    		data_toggle = 0;
    		IR_EVENT = 0;
    	}
    	break;

    // Space pulse is measured
    case 2:
    	//dbgstr[0] = 0;
    	//sprintf(dbgstr, "\r\n CAPTURE VALUE ON QUIET TIME: %d", CAPTURE);
    	//TxData(dbgstr);
    	if (CAPTURE > QUIET_MIN && CAPTURE < QUIET_MAX){
    		// Frame start is good, begin shifting bits
    		bitcount = 32;
    		IR_TIMER = 80; //80
    		T1 = 3;
    		ADDRESS = 0;
    		COMMAND = 0;

    	} else {
    		// Frame is already corrupt, start over!
    		T1 = 0;
    		data_toggle = 0;
    		IR_EVENT = 0;
    	}
    	break;

    // Incoming datastream
    // When we get here, we have validated the start of the frame and we can now process data bits
    case 3:
    	if(data_toggle == 0){
    		PULSETIME = CAPTURE;		// the pulse width is captured here, as the remote control often uses a RC clock
    									// which tends to drift badly with temp and humidity
    		data_toggle = 1;

    	} else {
    		// Compare the time of the space after the pulse
    		if(CAPTURE > PULSETIME + 350){
    			// Space is much longer than mark, we have a logic '1'
    			IR_DATA = IR_DATA >> 1;
    			IR_DATA |= 0x80000000;

    		} else {
    			// Space is more or less the same as the pulse, we have a logic '0'
    			IR_DATA = IR_DATA >> 1;
    			IR_DATA &= ~0x80000000;
    		}
    		data_toggle = 0;
    		bitcount--;
    		if (bitcount == 0){
    			T1 = 4;									// Frame is complete, change state
    		}

    	}

    	break;

   // Complete frame is read, unpack to fields
    case 4:
    	ADDRESS = *(((uint16_t *)&IR_DATA) + 0);		// Select lower word (CAUTION: ENDIAN-NESS HERE)
    	COMMAND = *(((uint16_t *)&IR_DATA) + 1);		// Select upper word (CAUTION: ENDIAN-NESS HERE)

    	dbgstr[0] = 0;
    	sprintf(dbgstr, "\r\n**IR Event:\r\nAddress: %04X   Command: %04X", ADDRESS, COMMAND);
    	TxData(dbgstr);

    	T1 = 0;											// Finished, reset state for next time
    	data_toggle = 0;								// Reset data toggle
    	IR_DATA = 0;									// Clear receive register for next time
    	IR_EVENT = 1;									// Set event
    	break;

    // Default case, out of state, timer will reset it
    default:
    	break;


    }

}

//-----------------------------------------------------------------------------
// Name: SYS_TICK_SVC
// Function: A routine called in the system ticker used to derive time delays
// Parameters: void
// Returns: void
//-----------------------------------------------------------------------------
void IR_SYS_TICK_SVC(void){
	// This code is called every 1ms

	if (T1 > 2){
		// IR routines are in data reception mode
		IR_TIMER--;
		if (IR_TIMER == 0){
			T1 = 0;
			data_toggle = 0;
			IR_DATA = 0;
			ADDRESS = 0;
			COMMAND = 0;
			IR_EVENT = 0;
		}

	}

}


// TIM 1 CH 2 Interrupt Handler
//--------------------------------
void TIM1_CC_IRQHandler(void){
	IR_IRQ_HNDL();
}
