//
//                            Filename: lcd.h
//                            Author: Sonic2k
//                            Purpose: Header file for lcd driver library lcd.c
//
//                            Revision History
//                            ----------------
//                               20-12-15: Created newest version
//
//
//-------------------------------------------------------------------------------------------------------------
#ifndef LCD_h
#define LCD_h

#include "bsp.h"

// Definitions, constants, globals, etc...
//-----------------------------------------

#define LCD_DATAPORT  LCD_PORT
#define RS LCD_RS
#define EN LCD_E

// Function Prototypes
//---------------------

void InitLCD(void);
void WriteData(unsigned char *array);
void SetAddress(unsigned char address);
void ClearDisplay(void);
void HomeCursor(void);

#endif
