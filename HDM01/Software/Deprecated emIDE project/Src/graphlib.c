//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                  Filename: GraphLib.c
//   Function: Display output routines for graphics displays
//              This version is a great improvement over the previous code- stuff is named properly, etc..
//              Version: 2.0.0.0
//              Date: July 2017
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "display.h"



//----------------------------------------------------------------------------------------------------------------------
// Name: OutChar (renamed from PutChar to prevent conflicts with similar named functions in other libs esp. Linux code)
// Function: Put a character of a specified font on the display at the specified location
// Parameters: character (ASCII), Font Type (int)
// Effects: DISP_COLUMN is updated
// Returns: void
//-----------------------------------------------------------------------------------------------------------------------
void OutChar(unsigned char ascii_char, const int *fonttype){
                    unsigned char *px;                      /* Declare pointer variable */
                    unsigned int font_ptr;                  /* Font array address storage */
                    unsigned char font_header;
                    unsigned char rcnt;
                    unsigned char run_length;
                    unsigned char char_height;
                    unsigned char ref_height;
                    px = 0;                                 /* Reset pointer at runtime */
                    font_ptr = fonttype[ascii_char];
                    px = (px + (font_ptr));                 /* Set pointer to point to font data */

 /* Process character's header information */
                    font_header = *px;                      /* Retrieve font header (info) */
                    run_length = (*px & 0x1F);              /* Extract run-length value */
                    char_height = (*px & 0xC0);             /* Extract cell height bits */
                    char_height = ((char_height >> 6) & 0x03);
                    ref_height = char_height;
                    char_height++;                          /* Offset by 1 */
                    px++;                                   /* Point to next byte (start of font data) */

/* Start drawing the character on the LCD */
                    while(char_height != 0){
                              for (rcnt = 0; rcnt < run_length; rcnt++){
                                        eWriteDispData(*px);           /* Put glyph data on LCD */
                                        px++;                         /* Increment pointer */
                              }
                              eWriteDispData(0x00);           /* Inter-character whitespace */
                              char_height--;
                              if (char_height != 0){
                                        DISPLAY_ROW++;      /* If more than 1 row high, switch to next line */
                                        DISPLAY_COLUMN = DISPLAY_COLUMN - run_length;
                                        DISPLAY_COLUMN--;
                              }
                    }
/* Restore original display row */
                    DISPLAY_ROW = (DISPLAY_ROW - ref_height);

}

//----------------------------------------------------------------------------------------------
// Name: OutString
// Function: Output string at specified location on display
// Parameters: String, Pointer to Font Index Table
// Returns: void
//----------------------------------------------------------------------------------------------
void OutString(const char *string, const int *fontname){
          unsigned int textptr = 0;
          for (;;){
                    if ((string[textptr]) != 0){
                    OutChar(string[textptr], fontname);
                    textptr++;
                    } else {
                    break;
                    }
          }
}

