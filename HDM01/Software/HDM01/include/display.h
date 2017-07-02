//
//                      display.h
//          Header file for display driver display.c
//
//
//------------------------------------------------------------------------------------------------------------
#ifndef __DISPLAY_H
#define __DISPLAY_H

// Constants and definitions
//---------------------------
#define X_SIZE 112
#define Y_SIZE 16           // 112 x 16 graphics display
#define DISPLAY_ROWS (Y_SIZE / 8)


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
void WriteDisplayData(unsigned char bmp);
void SetXY(unsigned char x, unsigned char y);
unsigned char GetX(void);
unsigned char GetY(void);

#endif
