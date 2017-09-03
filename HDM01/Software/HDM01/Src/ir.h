//
//						Filename: ir.h
//						Header file for ir.c
//
//
//-------------------------------------------------------------------------------------------------------------------------

#ifndef __IR_H_
#define __IR_H_

#include <stdint.h>
// Externs, defines, constants, structs
//-----------------------------------------

extern unsigned char IR_EVENT;
extern uint16_t ADDRESS;
extern uint16_t COMMAND;
// Function Prototypes
//------------------------------------------
void InitIR(void);
void IR_IRQ_HNDL(void);
void IR_SYS_TICK_SVC(void);

#endif /* IR_H_ */
