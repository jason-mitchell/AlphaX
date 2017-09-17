//
//                      Header file for Board Support Package
//                      Alpha-X HDM01
//
//-----------------------------------------------------------------------------------------------------
#ifndef __BSP_H_
#define __BSP_H_



// VFD Display Port Pins

#define SDATA GPIO_Pin_0			// (PC0)
#define SCLK GPIO_Pin_1				// (PC1)
#define RST GPIO_Pin_2				// (PC2)
#define BUSY GPIO_Pin_3				// (PC3)

// Control Signals
#define POWER_RELAY GPIO_Pin_6		// (PC6)
#define HEADPHONE_RELAY GPIO_Pin_7	// (PC7)

// Software driven SPI bus (to DIR and Front Panel ASIC)
#define MOSI GPIO_Pin_0				// (PB0)
#define MISO GPIO_Pin_1				// (PB1)
#define MCLK GPIO_Pin_2				// (PB2)
#define SS_FP GPIO_Pin_2			// (PA2)
//#define CS_DIR GPIO_Pin_3			// (PA3)

// Digital Interface Receiver
//#define DIR_RST GPIO_Pin_5			// (PC5)

// Front Panel ASIC (Xilinx XC9572 loaded with frontpanel.jed)
#define RESET_FP GPIO_Pin_1			// (PA1)
#define CLK_500Hz GPIO_Pin_4		// (PC4)


#endif
