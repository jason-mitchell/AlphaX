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
(
			SCLK,
			MOSI,
			SS,
			PDOUT,
			TFLAG
    );

input SCLK;
input MOSI;
input SS;
output reg[7:0]PDOUT;
output reg TFLAG;
reg[3:0] BITCNT = 0;


always @ (BITCNT)
begin
		if (BITCNT == 8)
			TFLAG = 1;
		else
			TFLAG = 0;
end

always @ (posedge SCLK)
if (~SS) begin
	PDOUT[7:0] <= {PDOUT[6:0], MOSI};

end

always @ (posedge SCLK)
begin
	BITCNT <= BITCNT + 1;
	if (BITCNT >= 8)
		BITCNT <= 1;
end
endmodule
