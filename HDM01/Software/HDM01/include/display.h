//
//                      display.h
//          Header file for display driver display.c
//
//
//------------------------------------------------------------------------------------------------------------
#ifndef _DISPLAY_H
#define _DISPLAY_H


// Function Prototypes
//--------------------
void BitTimer(void);
void ResetTimer(void);
void ResetDisplay(void);
void InitDisplay(void);
void WriteByteDisplay(unsigned char data);
void ClearDisplay(void);
void PrintToDisplay(unsigned char *str);
void OverWriteDisplay(void);
void NextLine(void);

#endif
