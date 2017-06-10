//
//                  Author: Sonikku
//                  Alpha-X HDM01 Control Processor Firmware using STM32F052RBT8
//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Includes

//#include <stddef.h>
//#include "stm32f0xx_rcc.h"
//#include "stm32f0xx.h"
#include <stdio.h>
#include "stm32f0xx_conf.h"
#include "stm32f0xx_usart.h"

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
  while(nCount--)
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


//-------------------------------------------------------------------------------------------------------------------------------------
//              Interrupt Handlers
//-------------------------------------------------------------------------------------------------------------------------------------
void SysTick_Handler(void)
{
  timer++;
  if  (timer>500)
  {
    timerFlag = 1;
    timer = 0;
  }
}

void USART1_IRQHandler(void){

    if (USART_GetITStatus(USART1, USART_IT_RXNE)){

            rxchar = USART1->RDR;       // use the typedef to get the right register read, and to avoid using a cast
    }

    printf("Character received.\r\n");
    fflush(stdout);
}

//-------------------------------------------------------------------------------------------------------------------------------------
//                                          Main Function
//-------------------------------------------------------------------------------------------------------------------------------------
int main(void){

        SystemCoreClockUpdate();

        // Enable clocks to peripherals we use
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);				                // enable clock to GPIOC
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);                             // Enable clock to GPIOB
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);                          // Enable clock to USART 1
        //RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

        // Configure I/O pins on GPIO PORT C
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13;          // PC15, PC14, PC13
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                                   // Outputs
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                                  // Push pull
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;                                // 2MHz max speed
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;                                // No pull-ups or pull-downs
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        // Configure I/O pin on PORTB for the UART (PB6)
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);


        // Configure UART 1

        USART_InitStructure.USART_BaudRate = 9600;
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
        USART_InitStructure.USART_Parity = USART_Parity_No;
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
        USART_Init(USART1, &USART_InitStructure);

        USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);      // Enable receive interrupt....

        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART1 interrupts
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
        NVIC_Init(&NVIC_InitStructure);


        USART_Cmd(USART1, ENABLE);

        SysTick_Config(4800);

        printf("HDM01 Debug Console Starting... \r\n");
        fflush(stdout);

 for(;;){

        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        Delay(0x3FFFFF);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        Delay(0x3FFFFF);


 }
}
