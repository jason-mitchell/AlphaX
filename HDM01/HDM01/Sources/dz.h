//
//                            Filename: dz.h
//                            Author: Sonic2k
//                            Purpose: Header file for common code library dz.c        
//
//                            Revision History
//                            ----------------
//                               30-03-14: Created newest version by merging from older code repos
//
//
//-------------------------------------------------------------------------------------------------------------
#ifndef dz_h
#define dz_h

#define false 0
#define true 1

#define rd 1
#define wr 0


// Function Prototypes
//-------------------------------------------------------
void InitRTC(unsigned char modulus);
void InitPLL(void);
void ConfigCPU(unsigned char COPE, unsigned char COPT, unsigned char STPMODE, unsigned char SCI2POS, unsigned char I2CPOS);
void InitPTA(unsigned char Mask, unsigned char IOVal);
void InitPTB(unsigned char Mask, unsigned char IOVal);
void InitPTE(unsigned char Mask, unsigned char IOVal);
void InitPTD(unsigned char Mask, unsigned char IOVal);
void InitPTF(unsigned char Mask, unsigned char IOVal);

unsigned int GetCPUID(void);

void InitialiseI2C(void);
void SendI2CControl(unsigned char busaddress, unsigned char operation);
unsigned char WaitForI2CAck(void);
void SendI2CStop(void);
void WriteI2CData(unsigned char data);
void SendRepeatedStart(void);
unsigned char ReadI2CData(void);

#endif