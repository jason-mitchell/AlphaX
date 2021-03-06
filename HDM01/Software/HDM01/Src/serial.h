//
//			File: serial.h
//			Purpose: Header file for serial port driver serial.c
//
//
//
//
//------------------------------------------------------------------------------------------------------------------------

#ifndef __SERIAL_H_
#define __SERIAL_H_

// Globals
//---------

extern unsigned char rcv_buffer[64];

// Typedefs


// Function Prototypes
void RxIRQHandler(void);
void TxData(unsigned char *Data);



#endif /* SERIAL_H_ */
