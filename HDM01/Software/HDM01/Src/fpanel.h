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


// Function Prototypes
//------------------------------------------
void InitFPIface(void);
unsigned char FpReadWrite(unsigned char command, unsigned char op, unsigned char *data);

#endif /* FPANEL_H_ */