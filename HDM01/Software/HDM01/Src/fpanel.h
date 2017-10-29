//
//						Filename: fpanel.h
//						Header file for fpanel.c
//
//
//-------------------------------------------------------------------------------------------------------------------------

#ifndef __FPANEL_H_
#define __FPANEL_H_

// Externs, defines, constants, structs
//-----------------------------------------

// Commands
//-------------------------
#define NOP 0x00
#define WRITE_LED_PORT 0x01
#define READ_CHIP_ID 0x06
#define READ_VENDOR_ID 0x19
#define READ_PORT 0x1F

// Function Prototypes
//------------------------------------------
void InitFPIface(void);
unsigned char FpReadWrite(unsigned char command, unsigned char op, unsigned char *data);

#endif /* FPANEL_H_ */
