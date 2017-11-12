//
//							Filename: ui.h
//						  Header file for ui.c
//
//
//
//-------------------------------------------------------------------------------------------------------------

#ifndef __UI_H_
#define __UI_H_


// Constants

#define STANDBY 		0
#define ACTIVE 			1
#define USER_INPUT1 	2
#define SWITCH_ON 		3
#define VOLUME			4

#define INPUT_1			0		// S/PDIF TOSLINK #1
#define INPUT_2			1		// S/PDIF TOSLINK #2
#define INPUT_3			2		// ANALOG LINE IN

// Function prototypes
//--------------------------------------------
void SendParam(unsigned char param);
void ChangeUIState(unsigned char new_state);
void InitUI(void);
void ServiceUI(void);



#endif /* UI_H_ */
