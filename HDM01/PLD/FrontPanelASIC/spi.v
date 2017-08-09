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
module spi(
			SCLK,
			MOSI,
			PDOUT
    );

input SCLK;
input MOSI;
output reg[7:0]PDOUT;

always @ (posedge SCLK)
begin
	PDOUT[7:0] <= {PDOUT[6:0], MOSI};
end
endmodule
