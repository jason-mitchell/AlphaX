//
//                            Filename: main.c
//                            Main Source code for the Alpha-X headphone amplifier
//                            Author: Jason "Sonic2k" Mitchell
//
//
//
//
//----------------------------------------------------------------------------------------------------------------------


// Header Includes
//---------------------
#include <hidef.h> 
#include "derivative.h"
#include "bsp.h"
#include "timer.h"
#include "dz.h"
#include "lcd.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "encoder.h"

unsigned char buffer[16];



//-----------------------------------------------------------------------------------------------------------------
//                                            Main Function
//-----------------------------------------------------------------------------------------------------------------
void main(void) {

            ConfigCPU(0,0,1,1,1);                   // Configure CPU out of reset...
            InitPLL();                              // Initialize and start up the PLL and run from it  
            InitRTC(0x13);                          // Initialize system tick

            APCTL1 = 0;                             // Configure PORT A for digital I/O
            InitPTA(0xFF, 0x00);		            // PORT A is used for LCD data....          
            InitPTD(0x31, 0x30);                    // Use PTD0 for initial debug...
            PTDSC = 0x02;                           // Edge/level and IRQ enabled...
            PTDPS = 0x08;                           // PTD2, PTD3 interrupt capable            
            PTDSC_PTDACK = 1;                       // Clear spurious interrupt
            
            InitTimer();
            EnableInterrupts;
            InitLCD();
            (void)memset(buffer, 0, 16);
            (void)sprintf(buffer, "    Alpha-X");
            WriteData(buffer);
            SetAddress(0x40);
            (void)memset(buffer, 0, 16);
            (void)sprintf(buffer, "    Welcome");
            WriteData(buffer);
            
            Timer(200);
            ClearDisplay();
            InitEncoder();            
            for(;;){
                    HomeCursor();
                    (void)memset(buffer, 0, 16);
                    (void)sprintf(buffer, "Encoder: %u         ", encoder_count);
                    WriteData(buffer);
                    Timer(50);
                    
                    //Timer(100);
                    //DEBUG_OUT = 1;
                    //Timer(100);
                    //DEBUG_OUT = 0;
          }

}

//----------------------------------------------------------------------------------------------------------------
//                                      Interrupt Handlers
//----------------------------------------------------------------------------------------------------------------
// RTC interrupt Handler
//-----------------------

 interrupt 25 void RTCInt(void) {          
          RTCSC |= (RTCSC_RTIF_MASK);             	// Clear interrupt flag          
          TimerTask();   
          TimerToggle();    
 }
 

 // I/O port Interrupt handler
 //----------------------------
 interrupt 22 void IOIRQ(void){  
        ServiceEncoder();
        PTDSC_PTDACK = 1; 
    
 }
 
  
 // SCI1 Interrupt Handler
 //------------------------
 
 interrupt 17 void SCI1Rx(void){
          //RxSCI1();
          
 }
 // SCI2 Interrupt Handler
 //------------------------
 
 interrupt 20 void SCI2Rx(void){
          //RxSCI2();          
	
 }
 
 
// ADC Interrupt Handler
//-----------------------
interrupt 23 void ADCIRQ(void){
          //ADC_IRQ_HANDLER();
          
}

// Low voltage detect Interrupt Handler
//-------------------------------------
interrupt 3 void LVDIRQ(void){
          //LVD_IRQ_HANDLER();
}

// Software interrupt/exception/event handler
//-------------------------------------------
interrupt 1 void SWIIRQ(void){
          ;

}


