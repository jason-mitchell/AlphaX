//
//						Filename: spi.h
//						Header file for spi.c
//
//
//-------------------------------------------------------------------------------------------------------------------------

#ifndef __SPI_H_
#define __SPI_H_

// Externs, defines, constants, structs
//-----------------------------------------
#define MSB_FIRST 1
#define LSB_FIRST 0

// Function Prototypes
//------------------------------------------
void InitSPI(void);
unsigned char SPITransceive(unsigned char data,  unsigned char bitorder);

#endif /* __SPI_H_ */
