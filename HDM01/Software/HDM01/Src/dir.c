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
//					FILENAME: dir.c
//					Purpose: Control library for Burr-Brown PCM9210/9211 Digital Audio interface
//					Dependencies:
//						1. An SPI peripheral
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

#include "dir.h"
#include "stm32f0xx_gpio.h"
#include "spi.h"


// Name: ReadDIRReg
// Function: Read a register within the PCM9211
// Parameters: Register address, address where read shall be stored
// Returns: void
//------------------------------------------------------------------
void ReadDIRReg(unsigned char regaddr){
	unsigned char RADR;
	unsigned char REGDR;

	RADR = regaddr & 0x7F;
	RADR |= 0x80;								// MSB = 1 for READ
	GPIO_ResetBits(GPIOA, SS_DIR);				// Lower ~SS
	SPITransceive(RADR, MSB_FIRST);
	REGDR = SPITransceive(0x00, MSB_FIRST);
	GPIO_SetBits(GPIOA, SS_DIR);				// Raise ~SS

}

// Name: InitDIR
// Function: Reset PCM9210/9211 and bring it into initial state
// Parameters: void
// Returns: void
//---------------------------------------------------------------
void InitDIR(void){

	GPIO_SetBits(GPIOA, SS_DIR);				// Ensure ~SS pin is pulled high
	GPIO_SetBits(GPIOC, RESET_DIR);				// Release reset from DIR


}
