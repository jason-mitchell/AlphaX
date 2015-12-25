//
//	     	Filename: dz.c
//		Purpose: Common routines for the Freescale MC9S08DZ microcontrollers
//	     	Author: Sonic2k
//		Date: 21/02/2013
//
//
//		Revision History:
//		-----------------
//                  30-04-2013: Added Serial port methods
//                  02-08-2013: Changed I2C timing a touch, to allow ATMEL EEPROMs to cope
//
//
//--------------------------------------------------------------------------------------------------------------

#include "derivative.h"   
#include "dz.h"



// Name: InitRTC
// Function: Initialise the RTC with the passed parameter
//--------------------------------------------------------
void InitRTC (unsigned char modulus){
          RTCMOD = modulus;             /* Get passed modulo parameter */
          RTCSC = 0x39;                 /* Start RTC timer up */
}

// Name: InitPLL
// Function: Initialise PLL to clock CPU at 40MHz (20MHz bus speed)
//-------------------------------------------------------------------          
          
void InitPLL(void) {
           MCGC2 = 0x36;
           while ((MCGSC & 0x02) != 0x02){
            ;        
           }
/* OSC has started up successfully, continue initialising PLL */                              
           MCGC1 = 0xB8;
           while ((MCGSC & 0x10) == 0x10){
                    ;
           }
/* Internal reference started up, wait for clock mode to set */
           while ((MCGSC & 0x0C) != 0x08){
                    ;
           }
/* Mode set, now set divider */
           MCGC1 = 0x90;
           MCGC3 = 0x4A;

/* Wait for PLL to lock */   
           while ((MCGSC & 0x20) != 0x20){
                    ;
           }

/* PLL Locked, change CPU clock */
           MCGC1 = 0x10;

}

// Name: ConfigCPU
// Function: Configure the SYSTEM OPTIONS registers
// Parameters: COPE - Enable/disable COP watchdog
//-------------------------------------------------
void ConfigCPU(unsigned char COPE, unsigned char COPT, unsigned char STPMODE, unsigned char SCI2POS, unsigned char I2CPOS){
          unsigned char temp_sopt1 = 0;

          
          // Process COP configuration bits
          //-------------------------------
          if (COPE == true){
                    COPT = COPT << 6;                       // Align the bits
                    COPT = COPT & 0xC0;                     // Mask off stuff we are not using
                    temp_sopt1 = temp_sopt1 | COPT;         // Insert bits                   
                    
          }
          
          // Process STOP mode enable bit
          //------------------------------
          if (STPMODE == true){
                    temp_sopt1 |= 0x20;
          }
          
          // Process Serial Port 2 Pin selection
          //------------------------------------
          if (SCI2POS == true){
                    temp_sopt1 |= 0x10;
          }
          
          // Process I2C Pin selection
          //---------------------------
          if (I2CPOS == true){
                    temp_sopt1 |= 0x08;
          }
          
          SOPT1 = temp_sopt1;
          SOPT2 = 0x00;
          
}


// I/O Port Setup Routines
//--------------------------------------------------------------------

void InitPTA(unsigned char Mask, unsigned char IOVal){
          PTAD = 0x00;                  	// initial reset of the port
          PTADD = Mask;                 	// initialize I/O pin directions
          PTAD = IOVal;                 	// initialise I/O port pin logic levels
}

void InitPTB(unsigned char Mask, unsigned char IOVal){
          PTBD = 0x00;                  	// initial reset of the port
          PTBDD = Mask;                 	// initialize I/O pin directions
          PTBD = IOVal;                 	// initialise I/O port pin logic levels
}

void InitPTE(unsigned char Mask, unsigned char IOVal){
          PTED = 0x00;                  	// initial reset of the port
          PTEDD = Mask;                 	// initialize I/O pin directions
          PTED = IOVal;                 	// initialise I/O port pin logic levels
}

void InitPTD(unsigned char Mask, unsigned char IOVal){
          PTDD = 0x00;                  	// initial reset of the port
          PTDDD = Mask;                 	// initialize I/O pin directions
          PTDD = IOVal;                 	// initialise I/O port pin logic levels
}

void InitPTF(unsigned char Mask, unsigned char IOVal){
          PTFD = 0x00;                  	// initial reset of the port
          PTFDD = Mask;                 	// initialize I/O pin directions
          PTFD = IOVal;                 	// initialise I/O port pin logic levels
}



// Name: GetCPUID
// Function: Retrieve CPU ID as required by the bootloader and return it
//------------------------------------------------------------------------
unsigned int GetCPUID(void){
	unsigned int returnval;
	
	*(((char *)&returnval)+0) = SDIDH;
	*(((char *)&returnval)+1) = SDIDL;
		
	return returnval;	
	
}

// I2C BUS PERIPHERAL CONTROL FUNCTIONS
//--------------------------------------------------------------------------

// Name: InitialiseI2C
// Function: Initialises the I2C peripheral for use
//--------------------------------------------------
void InitialiseI2C(void){
          
          IICC1_IICEN = 1;    // Enable I2C
          IICC1_TXAK = 1;     // Do not generate ACKs, we are master...
          IICC1_MST = 0;      // Set to slave mode (which puts the I2C into stop mode actually)
          IICF = 0x02;        // Slow baudrate  = 0x99  fast = 0x01;
          IICS_SRW = 0;       // R/W bit set to zero!
          
          
}

// Name: SendI2CControl
// Function: issues I2C bus start, and the standard I2C control byte
//---------------------------------------------------------------------
void SendI2CControl(unsigned char busaddress, unsigned char operation){
          
          busaddress = busaddress & 0x7F;         // Delimit bus addresses past to 127 bit combinations
          busaddress = busaddress << 1;           // Left-align bits 7..0
          if (operation == rd){
                    busaddress |= 0x01;           // Set LSB (operation bit)
          }
          if (operation == wr){
                    busaddress &= ~0x01;          // Clear LSB (operation bit)
          }
          IICC1_TX = 1;                           // Set transmit mode
          IICC1_MST = 1;                          // Master mode set
          IICD = busaddress;                      // Send the control byte
          while (!(IICS_IICIF));                  // Wait for data to finish sending...
          IICS_IICIF = 1;                         // Clear the interrupt flag...
          
          
          
          
}
// Name: WaitForI2CAck
// Function: Waits for I2C bus acknowledge from I2C slave device
// Returns: 0x00 if ACK received properly
//          0x01 if ACK failed to arrive
//---------------------------------------------------------------
unsigned char WaitForI2CAck(void){
          unsigned int ACK_TIMER = 5000;
          unsigned char result = 0;
          
          while (IICS_RXAK == 1){
                    ACK_TIMER--;
                    if (ACK_TIMER == 0){
                              result = 0x01;
                              break;
                    }
          }

          return result;          
          
}

// Name: SendI2CStop
// Function: Sends STOP condition to I2C bus
//-------------------------------------------
void SendI2CStop(void){
          IICC1_MST = 0;                          // Send STOP condition
}
          
// Name: WriteI2CData
// Function: transmit a data byte on the I2C bus
//
//--------------------------------------------
void WriteI2CData(unsigned char data){
          IICD = data;
          while (!(IICS_IICIF));                  // Wait for data to finish sending...
          IICS_IICIF = 1;                                                 
}

// Name: SendRepeatedStart
// Function: Issues repeated start bit pattern on I2C bus
//--------------------------------------------------------
void SendRepeatedStart(void){
          IICC_RSTA = 1;          
          
          
}

// Name: ReadI2CData
// Function: Reads data from the I2C bus
//           Sends the STOP bit automatically at the end of the transfer
//-----------------------------------------------------------------------
unsigned char ReadI2CData(void){
          unsigned char read_data;
          IICC_TX = 0;                  // Set into receive mode      
          IICC_TXAK = 1;                // Host must send acknowledge...
          read_data = IICD;             // dummy read to generate clocks
          while (!(IICS_IICIF));        // Wait for data to finish sending...
          IICS_IICIF = 1;               // Data has arrived...
          IICC_MST = 0;                 // Set STOP CONDITION...
          read_data = IICD;
          return read_data;
}