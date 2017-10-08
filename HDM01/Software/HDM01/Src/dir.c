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


unsigned char Fs;				// Sampling frequency variable
unsigned char WS;				// Word size variable

// Name: ReadDIRReg
// Function: Read a register within the PCM9210/9211
// Parameters: Register address, address where read shall be stored
// Returns: void
//------------------------------------------------------------------
void ReadDIRReg(unsigned char regaddr, unsigned char *regdata){
	unsigned char RADR;
	unsigned char REGDR;

	RADR = regaddr & 0x7F;
	RADR |= 0x80;								// MSB = 1 for READ
	GPIO_ResetBits(GPIOA, SS_DIR);				// Lower ~SS
	SPITransceive(RADR, MSB_FIRST);				// Send address word
	REGDR = SPITransceive(0x00, MSB_FIRST);		// Send data as 0x00 to read SPI
	GPIO_SetBits(GPIOA, SS_DIR);				// Raise ~SS
	*regdata = REGDR;
}

// Name: WriteDIRReg
// Function: Write a register within the PCM9210/9211
// Parameters: Register Address, Value to be written
// Returns: void
//-----------------------------------------------------------------------
void WriteDIRReg(unsigned char regaddr, unsigned char regdata){
	unsigned char RADR;
	RADR = regaddr & 0x7F;
	RADR &= ~0x80;								// MSB = 0 for WRITE
	GPIO_ResetBits(GPIOA, SS_DIR);				// Lower ~SS
	SPITransceive(RADR, MSB_FIRST);				// Send address word
	SPITransceive(regdata, MSB_FIRST);			// Send data word
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
	Fs = 0;
	WS = 0;

}

// Name: GetSPDIFInfo
// Function: Retrieve specific info from the S/PDIF stream
//           We need the word length (Very important)
//			 We need to know if we're being fed a Dolby Digital or other compressed stream (we need to mute the DAC)
// Parameters: void
// Returns: 0 if successful, -1 if failed (failure is returned if the DIR is not locked to an external digital source)
//----------------------------------------------------------------------------------------------------------------------
int GetSPDIFInfo(void){
	int result = -1;
	unsigned char tempA;
	unsigned char tempB;
	unsigned char tempC;
	unsigned char tempD;
	unsigned char tempE;
	unsigned char tempF;


	ReadDIRReg(0x5A, &tempA);				// The transmitter we use (VIA Envy24 sound card)
	ReadDIRReg(0x5B, &tempB);				// Sends all these bits as '0'... stupid motherfucking cunts!!!
	ReadDIRReg(0x5C, &tempC);				// Looking into hacking the Windows Driver..
	ReadDIRReg(0x5D, &tempD);
	ReadDIRReg(0x5E, &tempE);
	ReadDIRReg(0x5F, &tempF);
	return result;
}

// Name: GetCalcFs
// Function: Use hardware features in the DIR to measure the PCM sampling rate
//           We need this for the VU meter
// Parameters: void
// Returns: 0 if complete, -1 if failed (usually due to no suitable digital signal or no signal)
//------------------------------------------------------------------------------------------------
int GetCalcFs(void){
	int result = -1;
	unsigned char temp;
	WriteDIRReg(0x37, 0x00);				// Set DIR port for target of measurement
	ReadDIRReg(0x39, &temp);
	if((temp & 0x80) == 0x80){
		return -1;							// Busy with measurement, return -1;
	}

	// We seem to have a measurement
	if((temp & 0x0F) > 0){
		Fs = temp & 0x0F;					// We have valid measurement, store it!
		return 0;							// Got measurement, return good status
	}

	return result;
}
