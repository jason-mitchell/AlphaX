//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//                              Filename: syscalls.c
//                              Stub function implementation for ARM GCC compiler (with newlib) and ARM Cortex processors
//                              Author: Sonic2k
//                              Date: 28 February 2015
//
//                              Since we don't have a real OS, most of these are STUB function to ensure the linker doesn't stop with errors.
//                              For redirection of streams stdin and stdout, this is the place to look where to put your code.
//
//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Includes
//---------------------
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include "stm32f0xx_conf.h"


// Local variables
//---------------------------
char *heap_end = NULL;


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// stdio Stub functions
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int _kill(int pid, int sig)
{
   errno = EINVAL;
   return -1;
}

void _exit (int status)
{
   _kill(status, -1);
   while (1) {}      /* Make sure we hang here */
}

int _read (int file, char *ptr, int len)
{
   int DataIdx;

   for (DataIdx = 0; DataIdx < len; DataIdx++)
   {
    // *ptr++ = __io_getchar();          // user to provide this...

   }
   return len;
}

int _write(int file, char *ptr, int len)
{
   int DataIdx;

   for (DataIdx = 0; DataIdx < len; DataIdx++)
   {
   //   __io_putchar( *ptr++ );                                        // user to provide this...
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);        // Wait for Empty
   USART_SendData(USART1, *ptr++);                                     // Send character

   }
   return len;
}

//-----------------------------------------------------------
// sbrk function - taken from GNU
// Heap allocation routine
//
//-----------------------------------------------------------
void * _sbrk_r(struct _reent *_s_r, ptrdiff_t nbytes) {
  extern char  __heap_start__;
  extern char  __heap_end__;
  char* base;

  if (heap_end == NULL) {
    heap_end = &__heap_start__;
  }
  base = heap_end;
  if (heap_end + nbytes > &__heap_end__) {
    return 0; // Heap overflow
  }
  heap_end += nbytes;
  return base;
}


int _close(int file)
{
   return -1;
}

int _isatty(int file)
{
   return 1;
}


int _lseek(int file, int ptr, int dir)
{
   return 0;
}

int _fstat(int file, struct stat *st)
{
   st->st_mode = S_IFCHR;
   return 0;
}
