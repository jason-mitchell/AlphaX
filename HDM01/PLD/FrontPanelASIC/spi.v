`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:18:42 08/09/2017 
// Design Name: 
// Module Name:    spi 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module spi
#(
// Command Codes
parameter NO_OPERATION = 'h00,
parameter WRITE_LED_PORT = 'h01,
parameter READ_CHIP_ID = 'h06,
parameter READ_VENDOR_ID = 'h19,
parameter READ_PORT = 'h1F,

// Constants for return
parameter CHIP_ID = 'h71,			// Constant returned when CHIP ID of the device is requested
parameter VENDOR_ID = 'hAE,		// Constant returned when VENDOR ID of the device is requested
parameter ACK = 'h01,				// Constant returned as ACK for legal commands
parameter NAK = 'h80					// Constant returned for NAK for errors or illegal commands
)
(
			SCLK,
			MOSI,
			MISO,
			SS,
			LEDPORT,
			NRST,
			BYTE_IN,
			INPUTPORT
    );

input SCLK;							// Serial clock
input MOSI;							// Serial Input
input SS;							// Slave Select
input NRST;							// Master reset (active low)
input [7:0] INPUTPORT;			// General-purpose Input Port 8 bits wide
output reg MISO = 0;				// Serial output
reg[7:0]SPIDATA_IN = 0;				// 8 bit data register for received SPI data
reg[7:0]SPIDATA_OUT = 0;		// 8 bit data register for transmitted SPI data
output reg[7:0]LEDPORT = 0;	// 8 bit LED output port
output reg BYTE_IN = 0;					// SPI Receive Event flag
reg[3:0] BITCNT = 0;				// Bit counter
reg[7:0] DEVCMD = 0;				// 8 bit device command register
reg CMDDATA = 0;					// Toggle between command and data phase

//----------------------------------------------------------------------------------------------------------------------------------------------------------
// Byte input processing
//----------------------------------------------------------------------------------------------------------------------------------------------------------
always @ (posedge BYTE_IN or posedge NRST) begin

		if (NRST)
			begin
			LEDPORT = 0;
			DEVCMD = 0;
			SPIDATA_OUT = 0;
			end
		else
			begin
				SPIDATA_OUT = 'h00;									// Assume we are to return 0x00
				if(CMDDATA == 0)
					begin
					DEVCMD = SPIDATA_IN;							// Byte received is the command field
				
					// Command decoding here, asynchronously load registers if a response is needed in the next SPI transaction
					case(DEVCMD)
						WRITE_LED_PORT: SPIDATA_OUT = ACK;	
						READ_CHIP_ID: SPIDATA_OUT = CHIP_ID;
						NO_OPERATION: SPIDATA_OUT = ACK;
						READ_VENDOR_ID: SPIDATA_OUT = VENDOR_ID;
						READ_PORT: SPIDATA_OUT = INPUTPORT;
						default: SPIDATA_OUT = NAK;
					endcase
					CMDDATA = 1;						// Next byte shall be data

					end
				else
					begin
					case(DEVCMD)
						WRITE_LED_PORT: LEDPORT = SPIDATA_IN;					
					endcase
					CMDDATA = 0;
				end
			end
			
		
end

//------------------------------------------------------------
// Serial Receiver
//------------------------------------------------------------
always @ (posedge SCLK)
if (~SS) begin													// gating action...
	SPIDATA_IN[7:0] <={MOSI, SPIDATA_IN[7:1]};		// Note order, this matches the endian-ness of the host CPU
end

//-------------------------------------------------------------
// Serial Transmitter
//-------------------------------------------------------------
always @ (posedge SCLK)
if (~SS) begin
	MISO = SPIDATA_OUT[BITCNT];							// Bit selector used generate bit stream 
end


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//																			BIT COUNTER
//----------------------------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------
// Serial Clock negative edge
//------------------------------------------------------------
always @ (negedge SCLK or posedge NRST) begin

					// External reset (reset device to known state.. from CPU)
					if(NRST) begin
						BITCNT = 0;
						BYTE_IN = 0;
					end
					else 
					// Normal operation
					begin
					BITCNT = BITCNT + 1;			// increment counter
					if (BITCNT == 8) begin
						BYTE_IN = 1;				// set event on this edge	
						BITCNT = 0;					// counter is cleared
						end
					else 
						BYTE_IN = 0;				// cleared with next incoming edge of SCLK
						
					end
end

endmodule