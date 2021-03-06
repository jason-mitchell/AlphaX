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
//					FILENAME: timers.c
//					Purpose: General-purpose timer functions using a timer interrupt
//
//
//
//-------------------------------------------------------------------------------------------------------------------------

// Includes
//----------

#include "timers.h"
#include <string.h>

// Local Variables
//----------------

unsigned int TimerVar;
timerCB tcb;

//----------------------------------------------------------------------------
// Name: InitTimers
// Function: Perform Initialization of the timer resources
// Parameters: void
// Returns: void
//----------------------------------------------------------------------------
void InitTimers(void){
	int r;

	for (r = 0; r < 8; r++){
		memset(tcb.timerobj[r].name, 0x00, 8);			// Initialize name field
		tcb.timerobj[r].state = 2;						// State = 2 i.e. free
		tcb.timerobj[r].timervar = 0;					// Timing counter is zero
	}


}

//----------------------------------------------------------------------------
// Name: CreateTimer
// Function: Create a Timer with the given name
// Parameters: Delay required, name
// Returns: Result (0 if successful, -1 if failure)
//----------------------------------------------------------------------------
int CreateTimer(unsigned int delay, char *name){
	int result = -1;
	int r;

	// Run a search for available timer resources...
	for (r = 0; r < 8; r++){
		if (tcb.timerobj[r].state == 2){
			// Resource is available here, we can allocate to it.
			strncpy(tcb.timerobj[r].name, name, 7);		// allocate name
			tcb.timerobj[r].timervar = delay;			// allocate delay
			result = 0;
			break;
		}
	}
	return result;
}

//--------------------------------------------------------------------------------
// Name: ControlTimer
// Function: Perform an action on a timer
// Parameters: name, action (1 - run, 0 - stop)
// Returns: Result
//-------------------------------------------------------------------------------
int ControlTimer(char *name, unsigned char action){
	int result = -1;
	int r;

	// Find the timer
	for (r = 0; r < 8; r++){
		if (strstr(tcb.timerobj[r].name, name) != NULL){
			// Timer matches by name.. do the necessary

			if (action == 1){
				tcb.timerobj[r].state = 1;						// State = 1 running
			}
			if (action == 0){
				tcb.timerobj[r].state = 0;						// State = 0 stopped
			}
			result = 0;
			break;
		}
	}

	return result;
}
//----------------------------------------------------------------------------
// Name: ReleaseTimer
// Function: Release timer with given name
// Parameters: name
// Returns: result (0 if successful, -1 if timer not found or failed to release)
//--------------------------------------------------------------------------------
int ReleaseTimer(char *name){
	int result = -1;
	int r;

	// Find the timer
	for (r = 0; r < 8; r++){
		if (strstr(tcb.timerobj[r].name, name) != NULL){
			// Timer matches by name.. do the necessary
			memset(tcb.timerobj[r].name, 0x00, 8);			// Initialize name field
			tcb.timerobj[r].state = 2;						// State = 2 i.e. free
			tcb.timerobj[r].timervar = 0;					// Timing counter is zero
			result = 0;
			break;
		}
	}

	return result;
}

//----------------------------------------------------------------------------
// Name: IsTimerExpired
// Function: Check if the specified timer has expired, or not
// Parameters: Timer name
// Returns: 0 if timer running, 1 if timer expired, -1 if error
//----------------------------------------------------------------------------
unsigned char IsTimerExpired(char *name){
	unsigned char result = -1;
	int r;
	// Find the timer and get its state
	for (r = 0; r < 8; r++){
		if (strstr(tcb.timerobj[r].name, name) != NULL){
			// Timer matches by name.. do the necessary
			if(tcb.timerobj[r].state == 0){
				if(tcb.timerobj[r].timervar == 0){
					result = 1;
					break;
				}
			} else {
				result = 0;
				break;
			}
		}
	}
	return result;
}
//----------------------------------------------------------------------------
// Name: TimerSvc
// Function: Timer Servicing routine - called in your timer interrupt handler
// Parameters: void
// Returns: void
//-----------------------------------------------------------------------------
void TimerSvc(void){
	unsigned int r;
	unsigned char state_test;

	// This routine is based on the assumption that it shall be called exactly at 1.00mS intervals

	// Here we go thru a list of timers that might, or might not be active
	for(r = 0; r < 8; r++){
		state_test = tcb.timerobj[r].state;
		if(state_test == 1){
			// This timer is running... we can work with it!
			if(tcb.timerobj[r].timervar > 0){
				tcb.timerobj[r].timervar--;				// Decrement the timer
				if (tcb.timerobj[r].timervar == 0){
					tcb.timerobj[r].state = 0;			// Timer is now zero, change state...
				}
			}
		}
	}

}

