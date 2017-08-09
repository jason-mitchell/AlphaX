//
//						Header file for Standard Timer Library
//
//
//
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef __TIMERS_H_
#define __TIMERS_H_


// Individual Timer entity
typedef struct{
	unsigned char name[8];			// Name given to it in ASCII
	unsigned char state;			// Status byte (where 0 = expired or inactive, 1 = running, 2 = free for use)
	unsigned int timervar;			// Count-down variable loaded with a value that is decremented
}timer_entity;

// Collection of timer resources
typedef struct{
	timer_entity timerobj[8];
}timerCB;

// Function Prototypes
//---------------------
void InitTimers(void);
int CreateTimer(unsigned int delay, char *name);
int ReleaseTimer(char *name);
unsigned char IsTimerExpired(char *name);
void TimerSvc(void);
int ControlTimer(char *name, unsigned char action);

#endif /* TIMERS_H_ */
