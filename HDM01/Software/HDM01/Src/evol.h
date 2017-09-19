//
//								Filename: evol.h
//						Header file for source evol.c
//
//
//-------------------------------------------------------------------------------------------------------------
#ifndef __EVOL_H_
#define __EVOL_H_


// Defines
//---------

#define EVOL_CS	GPIO_Pin_9 		// (PC9)
#define EMUTE	GPIO_Pin_8		// (PA8)


// Function Prototypes
//----------------------
void SetVolume(unsigned char left, unsigned char right);
void MuteOn(void);
void MuteOff(void);


#endif /* EVOL_H_ */
