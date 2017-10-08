//
//								Alpha-X HDM01
//						Header file for dir.c - PCM9210/9211 driver
//
//
//----------------------------------------------------------------------------------------------------------

#ifndef __DIR_H_
#define __DIR_H_

// Definitions, constants
//-----------------------------------

#define RESET_DIR	GPIO_Pin_5			// PC5
#define SS_DIR		GPIO_Pin_3			// PA3

// Registers
#define NPCMDEF	0x28

// Function Prototypes
//-----------------------------------

void InitDIR(void);
void ReadDIRReg(unsigned char regaddr, unsigned char *regdata);
void WriteDIRReg(unsigned char regaddr, unsigned char regdata);
int GetSPDIFInfo(void);
int GetCalcFs(void);

#endif /* DIR_H_ */
