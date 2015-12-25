//
//                            Filename: encoder.h
//                            Author: Sonic2k
//                            Purpose: Header file for rotary encoder routines
//
//                            Revision History
//                            ----------------
//                               20-12-15: Created
//
//
//-------------------------------------------------------------------------------------------------------------
#ifndef encoder_h
#define encoder_h

#include "bsp.h"

// Definitions, constants, globals, etc...
//-----------------------------------------

#define PHASE_A PHA
#define PHASE_B PHB

extern unsigned int encoder_count;

// Function Prototypes
//---------------------

void ServiceEncoder(void);
void TimerToggle(void);
void InitEncoder(void);

#endif
