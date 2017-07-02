//
//                              Alpha-X HDM01 Firmware
//                      Filename: display.c
//                      Purpose: VFD Display driver (Noritake GU112X16G-7003)
//
//------------------------------------------------------------------------------------------------------------------------

// Includes
//----------
#include "display.h"
#include "bsp.h"
#include "stm32f0xx_conf.h"
#include <string.h>

unsigned char DISPLAY_COLUMN;
unsigned char DISPLAY_ROW;

unsigned char framebuffer[255];

// Functions
//-------------

void BitTimer(void){
    int x;
    for (x = 0; x < 2; x++){    //300 // 150
        ;
    }
}

void ResetTimer(void){
    int x;
    for (x = 0; x < 32000; x++){
        ;
    }

}

//---------------------------------------------------------------------------
// Name: PutGraphic
// Function: Put a graphic on the display from a source array
// Parameters: Pointer to graphics data
// Returns: void
//---------------------------------------------------------------------------
void PutGraphic(char *graphics){
    unsigned char a;
    unsigned char bmp;
    unsigned int ptr = 0;

    // Update cursor
    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x24);
    WriteByteDisplay(DISPLAY_COLUMN);
    WriteByteDisplay(0);
    WriteByteDisplay(DISPLAY_ROW);
    WriteByteDisplay(0);


    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x28);
    WriteByteDisplay(0x66);
    WriteByteDisplay(0x11);
    WriteByteDisplay(112);                      // xL  // x horizontal pixels / 2
    WriteByteDisplay(0x00);                     // xH
    WriteByteDisplay(0x01);                     // yL   // In this command these values are used to dimension the data received, NOT the actual location
    WriteByteDisplay(0x00);                     // yH
    WriteByteDisplay(0x01);                     // Fixed Value
    for(a = 0; a < 112; a++){
        bmp = graphics[ptr];
        bmp = (bmp * 0x0202020202ULL & 0x010884422010ULL) % 1023;
        WriteByteDisplay(bmp);
        ptr++;
    }

    DISPLAY_ROW++;
    // Update cursor
    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x24);
    WriteByteDisplay(DISPLAY_COLUMN);
    WriteByteDisplay(0);
    WriteByteDisplay(DISPLAY_ROW);
    WriteByteDisplay(0);

    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x28);
    WriteByteDisplay(0x66);
    WriteByteDisplay(0x11);
    WriteByteDisplay(112);                      // xL  // x horizontal pixels / 2
    WriteByteDisplay(0x00);                     // xH
    WriteByteDisplay(0x01);                     // yL   // In this command these values are used to dimension the data received, NOT the actual location
    WriteByteDisplay(0x00);                     // yH
    WriteByteDisplay(0x01);                     // Fixed Value
    for(a = 0; a < 112; a++){
        bmp = graphics[ptr];
        bmp = (bmp * 0x0202020202ULL & 0x010884422010ULL) % 1023;
        WriteByteDisplay(bmp);
        ptr++;
    }
}

//----------------------------------------------------------
// Name: ResetDisplay
// Function: Perform device reset using its reset pin
// Parameters: void
// Returns: void
//----------------------------------------------------------
void ResetDisplay(void){
      GPIO_ResetBits(GPIOC, RST);     // Reset is pulled low
      ResetTimer();
      GPIO_SetBits(GPIOC, RST);       // Reset is pulled high
      ResetTimer();
      ResetTimer();
}

//---------------------------------------------------------------------------
// Name: InitDisplay
// Function: Set up and initialize the VFD display
// Paramters:
// Returns:
//---------------------------------------------------------------------------
void InitDisplay(void){

        // Init command to reset to default
        WriteByteDisplay(0x1B);
        WriteByteDisplay(0x40);

        // Specify character set
        WriteByteDisplay(0x1B);
        WriteByteDisplay(0x52);
        WriteByteDisplay(0x00);

        // Set initial brightness level
        WriteByteDisplay(0x1F);
        WriteByteDisplay(0x58);
        WriteByteDisplay(0x04);     // 50%

        DISPLAY_ROW = 0;
        DISPLAY_COLUMN = 0;

}

//---------------------------------------------------------------------------
// Name: ClearDisplay
// Function: Clears the display in all modes
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------
void ClearDisplay(void){
    WriteByteDisplay(0x0C);
    DISPLAY_ROW = 0;
    DISPLAY_COLUMN = 0;
}
//---------------------------------------------------------------------------
// Name: OverWriteDisplay
// Function: Homes the cursor in text mode so that text is overwritten
//           emulation of the HD44780
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------
void OverWriteDisplay(void){
    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x24);
    WriteByteDisplay(0x00);
    WriteByteDisplay(0x00);
    WriteByteDisplay(0x00);
    WriteByteDisplay(0x00);
}
//------------------------------------------------------------------------------
// Name: NextLine
// Function: Sets text to start from the next logical line on the display
//           emulation of behaviour of the HD44780
// Parameters: void
// Returns: void
//-----------------------------------------------------------------------------
void NextLine(void){
    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x24);
    WriteByteDisplay(0x00);
    WriteByteDisplay(0x00);
    WriteByteDisplay(0x01);
    WriteByteDisplay(0x00);

}

//---------------------------------------------------------------------------
// Name: PrintToDisplay
// Function: Basic write to the display in text mode
//           The control codes are filtered out to prevent control issues
// Parameters: Pointer to array holding string data (null terminated
// Returns: void
//---------------------------------------------------------------------------
void PrintToDisplay(unsigned char *str){
    unsigned int r = 0;

    for(;;){
        if(str[r] == 0x00){
            break;
        }
        if (str[r] != 0x0B || str[r] != 0x0C || str[r] != 0x1B){

            WriteByteDisplay(str[r]);
            r++;
        }


    }


}
//---------------------------------------------------------------------------
// Name: WriteByteDisplay
// Function: Writes a byte out to the VFD display after ensuring the display
//           can accept data by polling BUSY
// Parameters: Byte to be written
// Returns: void
//---------------------------------------------------------------------------
void WriteByteDisplay(unsigned char data){
    int i;

    // Wait for busy to clear
    while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3) == 1){
        ;
    }
    for (i = 0; i < 8; i++){
        // Copy out a bit from the source
        if ((data & 0x01) == 0x01){
            GPIO_SetBits(GPIOC, SDATA);
        } else {
            GPIO_ResetBits(GPIOC, SDATA);
        }
        data = data >> 1;
        GPIO_SetBits(GPIOC, SCLK);      // Raise clock
        GPIO_ResetBits(GPIOC, SCLK);    // Lower clock

    }
}

//------------------------------------------------------------------------------------------
// Name: WriteDisplayData
// Function: Write graphics data to the display
//           This writes one bitmap chunk at a time to create compatibility with upper layer code
//           It also increments the internal counters
//------------------------------------------------------------------------------------------
void WriteDisplayData(unsigned char bmp){

    // Update cursor
    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x24);
    WriteByteDisplay(DISPLAY_COLUMN);
    WriteByteDisplay(0);
    WriteByteDisplay(DISPLAY_ROW);
    WriteByteDisplay(0);


    WriteByteDisplay(0x1F);
    WriteByteDisplay(0x28);
    WriteByteDisplay(0x66);
    WriteByteDisplay(0x11);
    WriteByteDisplay(0x01);                     // xL
    WriteByteDisplay(0x00);                     // xH
    WriteByteDisplay(0x01);                     // yL   // In this command these values are used to dimension the data received, NOT the actual location
    WriteByteDisplay(0x00);                     // yH
    WriteByteDisplay(0x01);                     // Fixed Value
    WriteByteDisplay(bmp);                      // Pattern we can recognize..
    DISPLAY_COLUMN++;
}

//----------------------------------------------
// Setters and getters
//----------------------------------------------
void SetXY(unsigned char x, unsigned char y){
    DISPLAY_COLUMN = x;
    DISPLAY_ROW = y;

}
unsigned char GetX(void){
    return DISPLAY_COLUMN;
}

unsigned char GetY(void){
    return DISPLAY_ROW;
}
