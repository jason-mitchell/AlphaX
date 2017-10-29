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

// Function prototypes
//--------------------------------------------
void SendParam(unsigned char param);
void ChangeUIState(unsigned char new_state);
void InitUI(void);
void ServiceUI(void);



#endif /* UI_H_ */
