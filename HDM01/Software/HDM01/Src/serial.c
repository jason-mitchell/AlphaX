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
//					FILENAME: serial.c
//					Purpose: General-purpose serial port stuff
//
//
//
//-------------------------------------------------------------------------------------------------------------------------

// Includes
//----------

#include "serial.h"
#include "stm32f0xx_rcc.h"

// Locals
//---------------
unsigned char rcv_buffer[64];		// Main receive buffer
unsigned int rcv_ptr;				// Receive buffer pointer


//------------------------------------------------------------------------
// Name: InitSerial
// Function: Initialise serial port stuff
// Parameters: void
// Returns: void
//------------------------------------------------------------------------



//------------------------------------------------------------------------
// Name: RxIRQHandler
// Function: Receive IRQ handling routine
// Parameters: void
// Returns: void
//------------------------------------------------------------------------
void RxIRQHandler(void){
	unsigned char byte;

    if (USART_GetITStatus(USART1, USART_IT_RXNE)){

            byte = USART1->RDR;       // Always use the provided typedefs to get the correct read type (no need then for casting)
        	if (rcv_ptr < 64){
        		rcv_buffer[rcv_ptr] = byte;
        		rcv_ptr++;
        	}
    }

}

//---------------------------------------------------------------------
// Name: TxData
// Function: Transmit character
// Parameters: Pointer to byte array to send
// Returns: void
//---------------------------------------------------------------------
void TxData(unsigned char *Data){
	unsigned int dptr = 0;

	for(;;){

		if (Data[dptr] == 0){
			break;
		}
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);        	// Wait for Empty
		USART_SendData(USART1, Data[dptr]);                                     // Send character
		dptr++;
	}



}

