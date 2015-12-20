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
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */



//----------------------------------------------------------------------------------------------------------------------
//                                            Main Function
//----------------------------------------------------------------------------------------------------------------------
void main(void) {

  EnableInterrupts; /* enable interrupts */
  /* include your code here */



  for(;;) {
    __RESET_WATCHDOG(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
