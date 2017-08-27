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


// Function Prototypes
//------------------------------------------
void InitSPI(void);
unsigned char SPITransceive(unsigned char data);

#endif /* __SPI_H_ */
