//
//                            Filename: lcd.c
//                            Function: Driver for HD44780 compatible LCD displays
//                            Author: Sonic2k
//
//
//
//
//
//-----------------------------------------------------------------------------------------------------------------------------

#include "derivative.h"
#include "lcd.h"


// Low-level databus emulation functions
//--------------------------------------
void PostData(unsigned char data){
          
     LCD_DATAPORT = data;     
}

void Strobe(void){
          unsigned int delay;

          for (delay = 0; delay < 43; delay++){
                    ;
          }
                    
          EN = 0;
          for (delay = 0; delay < 210; delay++){
                    
                 ;   
          }
          EN = 1;
          for (delay = 0; delay < 43; delay++){
                    ;
          }
          
}

void LatchData(unsigned char data){
          PostData(data);
          RS = 1;
          Strobe();
          
          
}

void LatchCmd(unsigned char cmd){
          PostData(cmd);
          RS = 0;
          Strobe();
          
}

void CommandTiming(void){
        unsigned int timing;
        for(timing = 0; timing < 1450; timing++){              // is for that time consuming clear screen and home cursor cmd
            ;
        }
}



// High-level abstraction
//----------------------------------------

// Name: InitLCD
// Function: Initialise the LCD for use
// Parameters: NumOfLines (1, 2, 4), CursorOption(0 = off, 1 = on)
// Returns: void
//----------------------------------------------------------------
void InitLCD(void){
          
         LatchCmd(0x0C);      
         LatchCmd(0x3F);
         LatchCmd(0x01);
         CommandTiming();
                    
}

// Name: WriteData
// Function: Write supplied data to the LCD, at the currently preset cursor/line
// Parameters: Pointer to data array
// Returns: void
//-------------------------------------------------------------------------------
void WriteData(unsigned char *array){
          unsigned char ptr = 0;
          
          for(;;){
            if (array[ptr] == 0){
                break;
            }
            LatchData(array[ptr]);
            ptr++;
                             
          }
                
}

// Name: SetAddress
// Function: Set the address of the cursor in the display
// Parameters: 7-bit address of the character
// Returns: void
//------------------------------------------------------------------------------
void SetAddress(unsigned char address){
    
    address |= 0x80;    // Set MSB to form the command
    LatchCmd(address);    
    
}

// Name: ClearDisplay
// Function: Performs complete clear of display contents and memory
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------
void ClearDisplay(void){
    
    LatchCmd(0x01);
    CommandTiming();    
        
}

// Name: HomeCursor
// Function: Homes the cursor without destroying display content
// Parameters: void
// Returns: void
//------------------------------------------------------------------------------
void HomeCursor(void){
    
    LatchCmd(0x02);
    CommandTiming();   
    
}