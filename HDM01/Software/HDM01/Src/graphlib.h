//-------------------------------------------------------------------------------------------------------
//                      Header for graphlib.c
//-------------------------------------------------------------------------------------------------------
#ifndef __GRAPHLIB_H_
#define __GRAPHLIB_H_


// Function Prototypes
//----------------------
void DrawBar(unsigned char width, unsigned char bitmask);
void ShiftBsline(unsigned char shift);
void SetInverse(unsigned char set, unsigned char mask);
void OutChar(unsigned char ascii_char, const int *fonttype);
void OutString(const char *string, const int *fontname);

#endif // __GRAPHLIB_H
