//
//                      Header file for RTC clock utility driver clock.c
//
//
//
//
//-------------------------------------------------------------------------------------------------------------------


#ifndef __CLOCK_H_
#define __CLOCK_H_


// Declarations
//--------------

// CurrentTime struct - Time-of-Day as at the read of the RTC
typedef struct{
	unsigned char hour;
	unsigned char minute;
	unsigned char second;

}CurrentTime;


// Function Prototypes
//------------------------
void InitClockHW(void);
uint32_t CheckClock(void);
void GetTimeNow(CurrentTime* TimeStruct);

#endif // __CLOCK_H_
