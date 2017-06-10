//
//                  Author: Sonikku
//                  Alpha-X HDM01 Control Processor Firmware using STM32F052RBT8
//                  (c) 2017 That Blue Hedgehog
//
//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Includes

//#include <stddef.h>
//#include "stm32f0xx_rcc.h"
//#include "stm32f0xx.h"
#include <stdio.h>
#include "stm32f0xx_conf.h"
#include "stm32f0xx_usart.h"
#include "bsp.h"
#include "i2c.h"


// Private typedefs
//----------------------

GPIO_InitTypeDef        GPIO_InitStructure;
USART_InitTypeDef       USART_InitStructure;
USART_ClockInitTypeDef  USART_ClockInitStructure;
NVIC_InitTypeDef        NVIC_InitStructure;

// Macros, definitions, constants
//--------------------------------

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
void SysTick_Handler(void)
{
  timer++;
  if  (timer>500)
  {
    timerFlag = 1;
    TickFlagI2C = 1;
    timer = 0;
  }
}

// USART 1 Interrupts
//---------------------
void USART1_IRQHandler(void){

    if (USART_GetITStatus(USART1, USART_IT_RXNE)){

            rxchar = USART1->RDR;       // Always use the provided typedefs to get the correct read type (no need then for casting)
    }

    printf("Character received.\r\n");
    fflush(stdout);
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
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);				                // enable clock to GPIOC
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);                             // Enable clock to GPIOB
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);                          // Enable clock to USART 1
//        RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);                            // Enable clock to I2C 1
        //RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

        // Configure I/O pins on GPIO PORT C
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13;          // PC15, PC14, PC13
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                                   // Outputs
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                                  // Push pull
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;                                // 2MHz max speed
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;                                // No pull-ups or pull-downs
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        // Configure I/O pins on PORTB
        // PB6 & PB7 -> UART1, PB8 & PB9 -> I2C1

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);
        GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_0);                        // Pin 6 and 7 are AF0



        // Configure UART 1

        USART_InitStructure.USART_BaudRate = 9600;
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

        InitI2C();                                                  // Initialize and enable I2C module

        SysTick_Config(4800);

        printf("HDM01 Debug Console Starting... \r\n");
        fflush(stdout);

 for(;;){

        TestI2C();
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        Delay(0x3FFFFF);
        //GeneralDelay();
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        //GeneralDelay();
        Delay(0x3FFFFF);


 }
}
