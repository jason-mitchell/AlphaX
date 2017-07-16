//---------------------------------------------------------------------------------------------------------------
//
//                        Real Time Clock Calendar Functions for STM32F052RBT8
//                                  Author: Sonic2k
//                                      July 2017
//
//
//
//---------------------------------------------------------------------------------------------------------------

#include "stm32f0xx_conf.h"
#include "clock.h"

// Definitions, typedefs, constants
//----------------------------------
#define RTC_CLOCK_SOURCE_LSE

RTC_InitTypeDef         RTC_InitStructure;


unsigned char CheckClock(void){
    unsigned char retval;
    if (RTC_ReadBackupRegister(RTC_BKP_DR0) != 0xFFFF){
        retval = 3;
    }
    return retval;
}
void InitClockHW(void){


}
