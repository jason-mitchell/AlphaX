//
//                            Filename: encoder.c
//                            Function: Driver and support routines for rotary encoders
//                            Author: Sonic2k
//                            Date: 20 December 2015
//
//
//
//
//
//-----------------------------------------------------------------------------------------------------------------------------

#include "derivative.h"
#include "encoder.h"
#include "bsp.h"


unsigned int encoder_count;
unsigned int toggle = 0;
unsigned char debounce;


// Name: ServiceEncoder
// Function: Service routine to be called when the encoder generates a hardware interrupt
// Parameters: void
// Returns: void
//----------------------------------------------------------------------------------------
void ServiceEncoder(void){
    
    if(PHASE_A == 0){
    
            if (PHASE_B == 0){
                if (encoder_count < 65535){
                    encoder_count++;
                }
                
                
            } else {
                if (encoder_count > 0){
                    encoder_count--;
                }
                
                
            }
    
    
            if (toggle != 0){
                toggle = 0;
                DEBUG_OUT = 1;
            } else {
                toggle = 1;
                DEBUG_OUT = 0;
            }

    }
    
    
}

// Name: TimerToggle
// Function: This function is to be called by the system ticker, it is used to generate debounce timing
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------------------------------
void TimerToggle(void){
    
    if(debounce > 0){
        debounce--;
    }
       
}

// Name: InitEncoder
// Function: Initialise variables used by this library
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------------------------------
void InitEncoder(void){
    
    debounce = 0;
    encoder_count = 0;    
    
}