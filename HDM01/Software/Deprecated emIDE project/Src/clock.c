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
RTC_TimeTypeDef         RTC_TimeStructure;
RTC_AlarmTypeDef        RTC_AlarmStructure;


__IO uint32_t AsynchPrediv = 0, SynchPrediv = 0;


uint32_t CheckClock(void){
    return RTC_ReadBackupRegister(RTC_BKP_DR0);
}

unsigned char ReadClkA(void){

    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
    return RTC_TimeStructure.RTC_Hours;

}
unsigned char ReadClkB(void){
    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
    return RTC_TimeStructure.RTC_Minutes;
}

unsigned char ReadClkC(void){
    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
    return RTC_TimeStructure.RTC_Seconds;
}
//--------------------------------------------------------------------------
//
//
//--------------------------------------------------------------------------
void InitClockHW(void){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    PWR_BackupAccessCmd(ENABLE);

    // Check backup register, if cleared we know the RTC lost power
    if(RTC_ReadBackupRegister(RTC_BKP_DR0) != 0x32440912){

        RCC_LSEConfig(RCC_LSE_ON);

        // Wait for LSE to become ready
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET){
                // Note that if there is any problem with the external oscillator, the code will hang here
        }

        // Set the RTC to be clocked from external source
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
        SynchPrediv = 0xFF;
        AsynchPrediv = 0x7F;

        // enable the clock to the module
        RCC_RTCCLKCmd(ENABLE);

        // Wait for synchronization with AHB
        RTC_WaitForSynchro();

        RTC_InitStructure.RTC_AsynchPrediv = AsynchPrediv;
        RTC_InitStructure.RTC_SynchPrediv = SynchPrediv;
        RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;
        RTC_Init(&RTC_InitStructure);

        RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32440912);
    }
}





