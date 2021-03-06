//
//							Filename: extflash.h
//						Header file for External Flash memory driver extflash.c
//
//
//-------------------------------------------------------------------------------------------------------------------

#ifndef __EXTFLASH_H_
#define __EXTFLASH_H_



// Definitions

#define FLASH_CS 	GPIO_Pin_8

// Instruction definitions for the ST Micro M95640W

#define RDSR	0x05
#define READ	0x03
#define WREN	0x06
#define WRITE	0x02
#define WRDI	0x04
#define WRSR	0x01

// Function Prototypes

int ReadFlash(unsigned int address, unsigned char *data);
int WriteFlash(unsigned int address, unsigned char data);

#endif /* EXTFLASH_H_ */
