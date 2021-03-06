//
//							Filename: level.h
//					Header for C source- level.c
//
//
//--------------------------------------------------------------------------------------------------------------------------------------------

#ifndef __LEVEL_H_
#define __LEVEL_H_

#include <stdint.h>


// Temporary pin assigments for debug
#define LD1		GPIO_Pin_11		// (PC11)
#define LD2		GPIO_Pin_12		// (PC12)
#define LD3		GPIO_Pin_3		// (PB3)
#define LD4		GPIO_Pin_4		// (PB4)
#define LD5		GPIO_Pin_5		// (PB5)


// Function Prototypes
//---------------------
unsigned char GetLevel(void);
void InitMeter(void);
void ServiceMeter(void);
void UpdateCall(void);

#endif /* LEVEL_H_ */
