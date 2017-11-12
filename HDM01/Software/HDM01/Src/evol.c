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
//					FILENAME: evol.c
//					Purpose: Electronic volume (e-volume) control with PGA2231
//					Dependencies:
//						1. SPI peripheral half-duplex (write only)
//
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

// Includes
//---------------
#include "evol.h"
#include "spi.h"
#include "stm32f0xx_gpio.h"
#include <stdbool.h>

//------------------------------------------------------------------
// Name: SetVolume
// Function: Set the volume according to passed parameters
// Parameters: Volume L-CH, Volume R-CH
// Returns: void
//-----------------------------------------------------------------
void SetVolume(unsigned char left, unsigned char right){

	SetSPIStatus(true);
    GPIO_ResetBits(GPIOC, EVOL_CS);			// lower CS
	SPITransceive(left, MSB_FIRST);			// Send left-channel volume
	SPITransceive(right, MSB_FIRST);		// Send right-channel volume
	GPIO_SetBits(GPIOC, EVOL_CS);
	SetSPIStatus(false);

}


