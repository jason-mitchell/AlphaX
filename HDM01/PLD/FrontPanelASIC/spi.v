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
parameter WRITE_LED_PORT = 'h01,
parameter READ_CHIP_ID = 'h06,
parameter WRITE_PWM_PORT = 'h04,

//Constants
parameter CHIP_ID = 'h71		// Constant returned when ID of the device is read
)
(
			SCLK,
			MOSI,
			MISO,
			SS,
			LEDPORT,
			NRST,
			PWMPORT,
    );

input SCLK;							// Serial clock
input MOSI;							// Serial Input
input SS;							// Slave Select
input NRST;							// Master reset (active low)
output reg MISO = 0;				// Serial output
reg[7:0]SPIDATA_IN;				// 8 bit data register for received SPI data
reg[7:0]SPIDATA_OUT = 0;		// 8 bit data register for transmitted SPI data
output reg[3:0]LEDPORT = 0;			// 8 bit LED output port
reg TFLAG = 0;			// SPI transaction latch flag, goes high each 8th clock
reg BYTE_IN = 0;					// SPI Receive Event flag
reg[3:0] BITCNT = 0;				// Bit counter
reg[7:0] DEVCMD = 0;				// 8 bit device command register
reg CMDDATA = 0;					// Toggle between command and data phase
reg BITCNT_RST;					// Asynchronous reset into BIT counter
output reg[7:0]PWMPORT = 0;	// PWM Output Duty Cycle Register


// Rising edge of TFLAG means byte is in from SPI
// Commands are also decoded here
//----------------------------------------------------
always @ (posedge BYTE_IN)
begin

	// Bit toggling
	//--------------
	if (CMDDATA == 0)
		begin
		CMDDATA <= 1;
		TFLAG = 1;
		end
	else
		begin
		CMDDATA <= 0;
		TFLAG = 0;
		end
		
end


//--------------------------------------
// Combinatorial - state machine
//--------------------------------------
always @ (CMDDATA, NRST, DEVCMD, SPIDATA_IN)
begin

	// First SPI packet in... we have a command field, store it
	//----------------------------------------------------------
	if (CMDDATA == 0)
		begin
			DEVCMD <= SPIDATA_IN;
			SPIDATA_OUT <= 0;
			//case(DEVCMD)
			//	
			//	default: SPIDATA_OUT <= 0;
			//endcase
		end
	
	// Second SPI packet in.. process the commands
	//----------------------------------------------------
	else
		begin
			case(DEVCMD)				
				WRITE_LED_PORT: LEDPORT <= SPIDATA_IN;
				READ_CHIP_ID: SPIDATA_OUT <= CHIP_ID;
				WRITE_PWM_PORT: PWMPORT <= SPIDATA_IN;
				default: SPIDATA_OUT <= 0;
			endcase
		end
		
	// Device reset	
	if (NRST)
		begin
			DEVCMD <= 0;
			LEDPORT <= 0;
			SPIDATA_OUT <= 0;
		end

end

//----------------------------------------------------------------------------
// Combinatorial - compare count of BITCNT and set TFLAG to level accordingly
// TFLAG is a needle pulse of very short duration.
//----------------------------------------------------------------------------
always @ (BITCNT)
begin
			
		if (BITCNT == 8)
			begin
			BYTE_IN = 1;
			BITCNT_RST = 1;
			end
		else
			begin
			BYTE_IN = 0;
			BITCNT_RST = 0;
			end
end

//------------------------------------------------------------
// Serial Engine
// Transmission is LSB first (full duplex SPI)
//------------------------------------------------------------
always @ (posedge SCLK)
if (~SS) begin
	SPIDATA_IN[7:0] <={MOSI, SPIDATA_IN[7:1]};		// Note order, this matches the endian-ness of the host CPU
	MISO = SPIDATA_OUT[BITCNT];							// Bit selector used generate bit stream // might need to fix this here...
end

//--------------------------------------
// Bit counter with asynchronous reset
//---------------------------------------
always @ (posedge SCLK, posedge BITCNT_RST) begin
	
	if (BITCNT_RST == 1) begin
		BITCNT = 0;
	end
	else begin
		BITCNT = BITCNT + 1;
	end
end		
endmodule
