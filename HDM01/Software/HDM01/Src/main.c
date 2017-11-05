//
//                  Author: Sonikku
//                  Alpha-X HDM01 Control Processor Firmware using STM32F052RBT8
//                  (c) 2017 That Blue Hedgehog
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
//					22/7/17 - Project moved to Atollic TrueStudio- Gain in performance apparent (code size down to 17k)
//					23/8/17 - This code works on the STM32F072RBT8 without change but we need to be careful.
//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Includes
//-----------
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"
#include "bsp.h"
#include "i2c.h"
#include "display.h"
//#include "graphic.h"
#include "graphlib.h"
//#include "stdfonts.h"
#include "clock.h"
#include "timers.h"
#include "serial.h"
#include "spi.h"
#include "fpanel.h"
#include "ir.h"
#include "dir.h"
#include "extflash.h"
#include "evol.h"
#include "audio.h"
#include "level.h"
#include "ui.h"

// Structs
//----------------------

GPIO_InitTypeDef        GPIO_InitStructure;
USART_InitTypeDef       USART_InitStructure;
USART_ClockInitTypeDef  USART_ClockInitStructure;
NVIC_InitTypeDef        NVIC_InitStructure;
EXTI_InitTypeDef   		EXTI_InitStructure;


CurrentTime				TimeOfDay;

// Macros, definitions, constants
//--------------------------------
#define SysTickInterval 1000				// Interval in uS 1000uS = 1mS
#define TickerRate SysTickInterval * 48

unsigned char LabelBgnd   [] = {"        "};
unsigned char Input1Label [] = {"INPUT 1"};
unsigned char Input2Label [] = {"INPUT 2"};
unsigned char Input3Label [] = {"INPUT 3"};
unsigned char Input4Label [] = {"INPUT 4"};

// Private variables
//--------------------

// Private function prototypes
//-----------------------------

// Private functions
//-------------------

void Delay(__IO uint32_t nCount)
{
  while(nCount--)             // let's get rid of shit like this!
  {
  }
}

// Global variables
//------------------
uint32_t timer=0;
uint8_t  timerFlag=0;

unsigned char toggle;

unsigned char testvar;
unsigned int rxchar;
unsigned char TickFlagI2C;

char arr[32];
unsigned char dbgstr[32];
unsigned int cnt;
unsigned char Delta;
unsigned char cnst;
unsigned char enc_cnt;
unsigned char rxd;
unsigned char tmp2;
unsigned int ADR;
unsigned char DAT;
char dbgout[32];
unsigned char VR;
unsigned char TMP;
unsigned int UI_TIMER;
unsigned char UI_UPDATE_FLAG;
unsigned char UI_FLASH_TOGGLE;

unsigned char ROT_EVENT;
unsigned char ROT_DIR;

// Timer that derives from the system ticker...
//-----------------------------------------------
void GeneralDelay(void){
    while(timerFlag == 0){
    }
    timerFlag = 0;

}

//---------------------------------------------------
// Name: UI Timer
// Service Routine
//---------------------------------------------------
void ServiceUITimer(void){
	if(UI_TIMER > 0){
		UI_TIMER--;
		UI_UPDATE_FLAG = 0;
	}
	if (UI_TIMER == 0){
		UI_UPDATE_FLAG = 1;
	}

}
//-------------------------------------------------------------------------------------------------------------------------------------
//              Interrupt Handlers
//-------------------------------------------------------------------------------------------------------------------------------------

// System Ticker Interrupt 1mS
//-----------------------------
void SysTick_Handler(void){

	TimerSvc();
	IR_SYS_TICK_SVC();				// Call function in IR library to service
	ServiceMeter();					// Service metering code
	ServiceUITimer();				// Here for now
	ServiceUI();
	timer++;
	if ((timer & 0x01) == 0x01){
		GPIO_SetBits(GPIOC, CLK_500Hz);
	} else {
		GPIO_ResetBits(GPIOC, CLK_500Hz);
	}
	if  (timer>500){
		timerFlag = 1;
		TickFlagI2C = 1;
		timer = 0;
  }
}

// USART 1 Interrupts
//---------------------
void USART1_IRQHandler(void){
	RxIRQHandler();
}


// PB12 IRQ, PB10 IRQ
// Todo: To be moved into the ui.c module
//------------------------------------------
void EXTI4_15_IRQHandler(void) {

	// PB4 - Headphone Jack
	//-----------------------
	if (EXTI_GetITStatus(EXTI_Line4)){
		EXTI_ClearITPendingBit(EXTI_Line4);
	}


	// PB10 External IRQ - ENCODER PUSH BUTTON
	//-----------------------------------------
	if (EXTI_GetITStatus(EXTI_Line10)){
		EXTI_ClearITPendingBit(EXTI_Line10);
	}


	// PB12 External IRQ - ENCODER PULSES
	//------------------------------------------
    if (EXTI_GetITStatus(EXTI_Line12)){

    	// Capture the direction and raise an event
    	ROT_EVENT = 1;
    	if(GPIO_ReadInputDataBit(GPIOB, LR) == 0){
    		ROT_DIR = 0;
    	} else {
    		ROT_DIR = 1;
    	}

        EXTI_ClearITPendingBit(EXTI_Line12);
    }
}

// Test Stuff
//------------

void TestI2C(void){
    while (I2C_GetFlagStatus(I2C1, I2C_ISR_BUSY) != RESET);                             // Wait if busy
    I2C_TransferHandling(I2C1, 0x80, 1, I2C_AutoEnd_Mode, I2C_Generate_Start_Write);    // Generate START, send address, send WRITE bit
    TickFlagI2C = 0;
    while (I2C_GetFlagStatus(I2C1, I2C_ISR_TXIS) == RESET){
        if (TickFlagI2C == 1){
            break;
        }
    }

    //I2C_SendData(I2C1, 0x55);                                                           // Send a byte
    //while(I2C_GetFlagStatus(I2C1, I2C_ISR_STOPF) == RESET);                             // Wait for byte to finish sending
    //I2C_ClearFlag(I2C1, I2C_ICR_STOPCF);                                                // Clear flags



   // delay(1);
   // while (I2C_GetFlagStatus(I2C1, I2C_ISR_BUSY) != RESET);
   // I2C_TransferHandling(I2C1, 0xA4, 6, I2C_AutoEnd_Mode, I2C_Generate_Start_Read);
   // while (numbytes--) {
   //     while(I2C_GetFlagStatus(I2C1, I2C_ISR_RXNE) == RESET);
   //         *buffer++ = I2C_ReceiveData(I2C1);
   // }
  //while (I2C_GetFlagStatus(I2C1, I2C_ISR_STOPF) == RESET);
  //I2C_ClearFlag(I2C1, I2C_ICR_STOPCF);
}


//-------------------------------------------------------------------------------------------------------------------------------------
//                                          Main Function
//-------------------------------------------------------------------------------------------------------------------------------------
int main(void){


        // System Startup and Configuration
        //------------------------------------
        SystemCoreClockUpdate();

        // Enable clocks to peripherals we use
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);				                // Port C
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);                             // Port B
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);                             // Port A
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);                          // Enable clock to USART 1
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);							// Clock to TIM2
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);							// Clock to SYSCFG



        // Configure I/O pins on GPIO PORT C
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_5 | FLASH_CS | EVOL_CS;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                                   // Outputs
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                                  // Push pull
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;                               // 10MHz since we have a display on this port
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;                                // No pull-ups or pull-downs
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_Init(GPIOC, &GPIO_InitStructure);


        // Initialise specific pins to levels
        GPIO_ResetBits(GPIOC, RESET_DIR);												// Hold DIR in reset
        GPIO_SetBits(GPIOC, RST);                                                       // Display's RST pin is high
        GPIO_ResetBits(GPIOC, POWER_RELAY);												// Power relay
        GPIO_ResetBits(GPIOC, HEADPHONE_RELAY);											// Headphone relay
        GPIO_SetBits(GPIOC, FLASH_CS);													// Flash CS pin
        GPIO_SetBits(GPIOC, EVOL_CS);													// E-volume CS pin


        // Configure I/O pins on PORTB
        //------------------------------------------------------

        GPIO_InitStructure.GPIO_Pin = MOSI | MCLK;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = MISO;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_Init(GPIOB, &GPIO_InitStructure);


        // Specific init of PB12 as an input for external IRQ and PB13 as normal input
        GPIO_InitStructure.GPIO_Pin = TICK | LR;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOB, &GPIO_InitStructure);


        SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource12);		// EXTI Line 0 -> PB12
        EXTI_InitStructure.EXTI_Line = EXTI_Line12;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;				// Rising edges only...
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;							// Is enabled!
        EXTI_Init(&EXTI_InitStructure);

        // Enable GPIO IRQ channel covering 4 thru 15
        //-------------------------------------------------
        NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);


        // Init of PB6 and PB7 for UART
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;						// USART Tx and Rx
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);
        GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_0);                        // Pin 6 and 7 are AF0 (USART Tx and RX)

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;									// PB11 PWM out for Power LED
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_Init(GPIOB, &GPIO_InitStructure);										// Pin 11 is an output
        GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_2);						// Alternate function 2 = (Timer 2 CH4)



        // Configure PORT A
        //--------------------------------------------------
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | EMUTE;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = SS_FP | SS_DIR | RESET_FP;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        // Initialize specific pins
        GPIO_SetBits(GPIOA, EMUTE);

        // Configure UART 1
        //-----------------------------------------------

        USART_InitStructure.USART_BaudRate = 115200;
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
        USART_InitStructure.USART_Parity = USART_Parity_No;
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
        USART_Init(USART1, &USART_InitStructure);

        USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);              // Enable receive interrupt....

        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		    // we want to configure the USART1 interrupts
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			    // the USART1 interrupts are globally enabled
        NVIC_Init(&NVIC_InitStructure);


        USART_Cmd(USART1, ENABLE);



        // Software Module Initializations
        //--------------------------------------
        UI_TIMER = 0;
        UI_UPDATE_FLAG = 0;
        UI_FLASH_TOGGLE = 0;

        InitClockHW();												// Init/check real-time clock
        InitTimers();												// Init Timer Library
        InitSPI();													// Bit-banged SPI interface
        InitFPIface();												// Initialize FPANEL (Xilinx XC9572)
        InitI2C();                                                  // Initialize and enable I2C module
        InitMeter();
        SysTick_Config(TickerRate);									// Initialize the System Tick
        InitIR();													// Initialize Infra-red module
        InitDIR();													// Initialize Digital audio rcvr
        InitAudioIF();												// Initialize digital audio interface

        // System Startup begins here...
        //------------------------------

        InitUI();
        cnt = 0;
        ADR = 0;

        ROT_EVENT = 0;

        // Set up DIR to accept digital audio on TOSLINK #1
        // In the absence of lock, it will still default to the analog input (in-built A/D converter)
        WriteDIRReg(0x34, 0xC4);

        //-----------------------------------------------------------------------------------------------------
        // System Superloop
        //-----------------------------------------------------------------------------------------------------

        for(;;){

        	ChangeUIState(STANDBY);

            while(1){
                // Monitor power button and IR and change state when they are activated....
                if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
                	break;
                }
                if(IR_EVENT == 1){
                	IR_EVENT = 0;
                	if (COMMAND == 0x0738){
                		break;
                	}
                }

            }

            // Button was pressed, power the system on
            //----------------------------------------------------
            ChangeUIState(SWITCH_ON);
            GPIO_SetBits(GPIOC, POWER_RELAY);					// Power amp on
            Delay(0x3FFFFF);									// time dealy NB** REFACTOR
            GPIO_SetBits(GPIOC, HEADPHONE_RELAY);				// Switch output relay on
            Delay(0x3FFFFF);
            IR_EVENT = 0;
    		ReadFlash(0x00, &VR);
    		SetVolume(VR, VR);			// Initialize volume control

    		ChangeUIState(ACTIVE);
            while(1){

            	// Check input signals
            	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
            		break;
            	}

            	// Rotary Encoder Events
            	if(ROT_EVENT == 1){
            		ROT_EVENT = 0;
            		if (ROT_DIR == 1){
            			VR += 2;
            			SendParam(VR);
            			ChangeUIState(VOLUME);
            			WriteFlash(0x00, VR);
            		} else {
            			VR -= 2;
            			if (VR > 250){
            				VR = 0;
            			}
            			SendParam(VR);
            			ChangeUIState(VOLUME);
            			WriteFlash(0x00, VR);
            		}

            		ReadFlash(0x00, &VR);
            		SetVolume(VR, VR);
            	}


            	// Remote Control Events
            	if (IR_EVENT == 1){
            		IR_EVENT = 0;
            		if(COMMAND == 0x0DD2){
            			VR += 2;
            			SendParam(VR);
            			ChangeUIState(VOLUME);
            			WriteFlash(0x00, VR);
            		}

            		if(COMMAND == 0x05DA){
            			VR -= 2;
            			if (VR > 250){
            				VR = 0;
            			}
            			SendParam(VR);
            			ChangeUIState(VOLUME);
            			WriteFlash(0x00, VR);
            		}

            		ReadFlash(0x00, &VR);
            		SetVolume(VR, VR);
            		if (COMMAND == 0x0738){
            			break;
            		}
            	}

            }

            //-------------------------------------------------------------------------------
            GPIO_ResetBits(GPIOC, HEADPHONE_RELAY);
            Delay(0x3FFFFF);
            GPIO_ResetBits(GPIOC, POWER_RELAY);
            while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
                ;
            }
            IR_EVENT = 0;

        }

}
