//
//
//                      I2C Driver for STM32F052RBT8
//                          Author: Sonic2k
//                             June 2017
//
//------------------------------------------------------------------------------------------------------------------------

// Includes
//-----------
#include "stm32f0xx_conf.h"


// Definitions, macros, constants
//-----------------------------------
GPIO_InitTypeDef        GPIO_InitStructure;
I2C_InitTypeDef         I2C_InitStructure;

// Functions
//-----------

// Name: InitI2C
// Function: Initializes I2C1 module, to the default pins PB8, PB9
//------------------------------------------------------------------
void InitI2C(void){

        // Initialize the I/O pins used for this...

        RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);                        // Enable clock to I2C 1

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;                              // Must be open-drain else I2C won't work correctly
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_Init(GPIOB, &GPIO_InitStructure);
        GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_1);
        GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_1);                        // Pin 8 and 9 are AF1

        I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;                                 // Enable I2C ACK
        I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;               // Enable Analog filter
        I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;                                  // Master Mode
        I2C_InitStructure.I2C_DigitalFilter = 0;                                    // No digital filter
        I2C_InitStructure.I2C_OwnAddress1 = 0x00;                                   // Slave address (we're master so we set this to zero)
        I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;   // Standard 7 bit addressing
        I2C_InitStructure.I2C_Timing =  0x4055AAAA;                                 // Thumb-sucked value (to be corrected using the software tool)
        I2C_Init(I2C1, &I2C_InitStructure);                                         // Write the configuration
        I2C_Cmd(I2C1, ENABLE);                                                      // Enable I2C1 module

}

