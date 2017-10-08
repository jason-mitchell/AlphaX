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
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"
#include "bsp.h"
#include "i2c.h"
#include "display.h"
#include "graphic.h"
#include "graphlib.h"
#include "stdfonts.h"
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

// Structs
//----------------------

GPIO_InitTypeDef        GPIO_InitStructure;
USART_InitTypeDef       USART_InitStructure;
USART_ClockInitTypeDef  USART_ClockInitStructure;
NVIC_InitTypeDef        NVIC_InitStructure;
TIM_TimeBaseInitTypeDef Timer_InitStructure;

CurrentTime				TimeOfDay;

// Macros, definitions, constants
//--------------------------------
#define SysTickInterval 1000				// Interval in uS 1000uS = 1mS
#define TickerRate SysTickInterval * 48

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

// Timer that derives from the system ticker...
//-----------------------------------------------
void GeneralDelay(void){
    while(timerFlag == 0){
    }
    timerFlag = 0;

}
//-------------------------------------------------------------------------------------------------------------------------------------
//              Interrupt Handlers
//-------------------------------------------------------------------------------------------------------------------------------------

// System Ticker Interrupt
//---------------------------
void SysTick_Handler(void){

	TimerSvc();
	IR_SYS_TICK_SVC();				// Call function in IR library to service
	ServiceMeter();					// Service metering code
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

        // Specific init of PB10 with a pull-up
        GPIO_InitStructure.GPIO_Pin = MENU;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);


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



        // TIM2 Module Configured for PWM on PB11 (Power LED inside the Marquardt Push Button)
        //--------------------------------------------------------------------------------------

        Timer_InitStructure.TIM_Prescaler = 1200;
        Timer_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
        Timer_InitStructure.TIM_Period = 500;		// PWM period value
        Timer_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
        Timer_InitStructure.TIM_RepetitionCounter = 0;
        TIM_TimeBaseInit(TIM2, &Timer_InitStructure);
        TIM_Cmd(TIM2, ENABLE);

        // Output Compare configuration
        //--------------------------------
        TIM_OCInitTypeDef outputChannelInit = {0,};
        outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
        outputChannelInit.TIM_Pulse = 2;	// PWM duty cycle  @ 25 LED quite bright  4 = nice and dim (needle pulse width)
        outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
        outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;
        TIM_OC4Init(TIM2, &outputChannelInit);
        TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

        // Software Module Initializations
        //--------------------------------------
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
        ResetDisplay();
        InitDisplay();
        PutGraphic(Graphic1);
        Delay(0x3FFFFF);
        ClearDisplay();
        cnt = 0;
        ADR = 0;

        // Set up DIR to accept digital audio on TOSLINK #1
        // In the absence of lock, it will still default to the analog input (in-built A/D converter)
        WriteDIRReg(0x34, 0xC4);

        //-----------------------------------------------------------------------------------------------------
        // System Superloop
        //-----------------------------------------------------------------------------------------------------
        for(;;){
            SetDispIntensity(1);
            while(1){
                SetXY(0, 0);
                ClearFB();
                GetTimeNow(&TimeOfDay);
                if (Delta != TimeOfDay.second){
                	Delta = TimeOfDay.second;

                    memset(dbgstr, 0 , 32);
                    TxData("PCM9210 Registers Read:\r\n");
                    ReadDIRReg(0x34, &TMP);
                    sprintf(dbgstr, "DIR Input Select Reg: %02X ", TMP);
                    TxData(dbgstr);



                    if (cnst == 0x55){
                    	cnst = 0xAA;

                    } else {
                    	cnst = 0x55;

                    }
                }
                memset(arr, 0, 32);
                sprintf(arr, "%2d:%02d:%02d", TimeOfDay.hour, TimeOfDay.minute, TimeOfDay.second);
                OutString(arr, Font1);
                SetXY(0, 1);
                memset(arr, 0 , 32);



                // Service Front Panel
                FpReadWrite(0x01, cnst & 0x01, &rxd);	// Update the LED port
                FpReadWrite(0x1F, 0x00, &rxd);			// Read the Encoder
                sprintf(arr, "Encoder: %02X", rxd);
                OutString(arr, Font1);
                UpdateFromFB();

                // Service the DIR

                // Monitor power button and IR
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
            SetDispIntensity(4);								// Raise brightness
            PutGraphic(Graphic1);								// Load graphics
            GPIO_SetBits(GPIOC, POWER_RELAY);					// Power amp on
            Delay(0x3FFFFF);									// time dealy NB** REFACTOR
            GPIO_SetBits(GPIOC, HEADPHONE_RELAY);				// Switch output relay on
            SetXY(0, 0);										// Set X-Y co-ords
            OutString("Welcome", Font2);						// Load a string
            UpdateFromFB();										// Update the display from the frame buffer
            Delay(0x3FFFFF);
            ClearFB();											// Clear frame buffer
            SetXY(0, 0);
            OutString("\x0F", Font1);
            SetXY(0, 1);										// Reset co-ords
            OutString("\x0E", Font1);							// Display bitrate indicator
            UpdateFromFB();

            // Wait for OFF command
            IR_EVENT = 0;
    		ReadFlash(0x00, &VR);
    		SetVolume(VR, VR);			// Initialize volume control
            while(1){
            	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
            		break;
            	}
            	if (IR_EVENT == 1){
            		IR_EVENT = 0;
            		if(COMMAND == 0x0DD2){
            			VR += 2;
            			WriteFlash(0x00, VR);
            		}

            		if(COMMAND == 0x05DA){
            			VR -= 2;
            			if (VR > 250){
            				VR = 0;
            			}
            			WriteFlash(0x00, VR);
            		}
            		ReadFlash(0x00, &VR);
            		SetVolume(VR, VR);			// send packet every time remote sends signal
            		if (COMMAND == 0x0738){
            			break;
            		}
            	}



            }
            // while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1){
                // Idle loop
//
//           }
            GPIO_ResetBits(GPIOC, HEADPHONE_RELAY);
            SetXY(0, 0);
            ClearFB();
            OutString("Bye", Font2);
            UpdateFromFB();
            Delay(0x3FFFFF);
            GPIO_ResetBits(GPIOC, POWER_RELAY);
            ClearDisplay();
            while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
                ;
            }
            IR_EVENT = 0;

        }

}
