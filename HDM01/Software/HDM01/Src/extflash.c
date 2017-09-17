//----------------------------------------------------------------------------------------------------------------------------------
//
//							Author: Sonikku
//
//                              ______
//	                      _.-*'"      "`*-._
//	                _.-*'                  `*-._
//	             .-'                            `-.
//	  /`-.    .-'                  _.              `-.
//	 :    `..'                  .-'_ .                `.
//	 |    .'                 .-'_.' \ .                 \
//	 |   /                 .' .*     ;               .-'"
//	 :   L                    `.     | ;          .-'
//	  \.' `*.          .-*"*-.  `.   ; |        .'
//	  /      \        '       `.  `-'  ;      .'
//	 : .'"`.  .       .-*'`*-.  \     .      (_
//	 |              .'        \  .             `*-.
//	 |.     .      /           ;                   `-.
//	 :    db      '       d$b  |                      `-.
//	 .   :PT;.   '       :P"T; :                         `.
//	 :   :bd;   '        :b_d; :                           \
//	 |   :$$; `'         :$$$; |                            \
//	 |    TP              T$P  '                             ;
//	 :                        /.-*'"`.                       |
//	.sdP^T$bs.               /'       \
//	$$$._.$$$$b.--._      _.'   .--.   ;
//	`*$$$$$$P*'     `*--*'     '  / \  :
//	   \                        .'   ; ;
//	    `.                  _.-'    ' /
//	      `*-.                      .'
//	          `*-._            _.-*'
//	               `*=--..--=*'
//
//
//					FILENAME: extflash.c
//					Purpose: Interface library for serial flash memories
//                           EN25Q32A, M95640W and others
//					Dependencies:
//						1. An SPI peripheral
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

// Included headers
//------------------

#include "extflash.h"
#include "spi.h"
#include "stm32f0xx_gpio.h"

// Locals
//-------


// Functions
//-----------------

//---------------------------------------------------
// Name: ReadStatus
// Function: Read status register of memory device
// Parameters: void
// Returns: Status Register
//--------------------------------------------------
unsigned char ReadFlashStatus(void){
	unsigned char status;

	GPIO_ResetBits(GPIOC, FLASH_CS);
	SPITransceive(RDSR, MSB_FIRST);
	status = SPITransceive(0x00, MSB_FIRST);
	GPIO_SetBits(GPIOC, FLASH_CS);
	return status;
}

void EnableWrite(void){
	GPIO_ResetBits(GPIOC, FLASH_CS);
	SPITransceive(WREN, MSB_FIRST);
	GPIO_SetBits(GPIOC, FLASH_CS);

}

//---------------------------------------------------
// Name: WriteFlash
// Function: Write data to FLASH memory
// Parameters:
// Returns:
//---------------------------------------------------
int WriteFlash(unsigned int address, unsigned char data){
	unsigned int addr;

	addr = address;

	// First stage- enable writes
	EnableWrite();

	// Second stage- write the byte
	GPIO_ResetBits(GPIOC, FLASH_CS);							// lower CS
	SPITransceive(WRITE, MSB_FIRST);							// Send cmd
	SPITransceive(*(((char *)&addr) + 1), MSB_FIRST);			// High address
	SPITransceive(*(((char *)&addr) + 0), MSB_FIRST);			// Low address
	SPITransceive(data, MSB_FIRST);								// Retrieve the data
	GPIO_SetBits(GPIOC, FLASH_CS);								// raise CS


}

//--------------------------------------------------
// Name: ReadFlash
// Function: Read data from FLASH memory
// Parameters:
// Returns:
//--------------------------------------------------
int ReadFlash(unsigned int address, unsigned char *data){
	unsigned int addr;
	unsigned char drd;

	addr = address;
	GPIO_ResetBits(GPIOC, FLASH_CS);		// lower CS
	SPITransceive(READ, MSB_FIRST);			// Send cmd
	SPITransceive(*(((char *)&addr) + 1), MSB_FIRST);			// High address
	SPITransceive(*(((char *)&addr) + 0), MSB_FIRST);			// Low address
	drd = SPITransceive(0x00, MSB_FIRST);			// Retrieve the data
	GPIO_SetBits(GPIOC, FLASH_CS);			// raise CS
	*data = drd;
	return 0;
}
