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


// Functions
//-------------

void BitTimer(void){
    int x;
    for (x = 0; x < 150; x++){    //300
        ;
    }
}

void ResetTimer(void){
    int x;
    for (x = 0; x < 32000; x++){
        ;
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

}

//---------------------------------------------------------------------------
// Name: ClearDisplay
// Function: Clears the display in all modes
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------
void ClearDisplay(void){
    WriteByteDisplay(0x0C);
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
        BitTimer();
        GPIO_SetBits(GPIOC, SCLK);      // Raise clock
        BitTimer();
        GPIO_ResetBits(GPIOC, SCLK);    // Lower clock
        BitTimer();

    }
}
