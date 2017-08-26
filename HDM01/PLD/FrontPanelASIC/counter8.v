`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:56:32 08/24/2017 
// Design Name: 
// Module Name:    counter8 
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
module counter8
(
    CLK,
    RST,
	 DIR,
    COUNT
    );

input CLK;						// Clock pulses in
input DIR;						// Count Direction control
input RST;						// Reset input
output reg [7:0] COUNT = 0; 		// Counter Register and output


always @ (posedge CLK)
	if(~RST) begin
		
		if (DIR)
			COUNT <= COUNT + 1;
		else
			COUNT <= COUNT - 1;
			
		if (RST)
			COUNT <= 0;
	end



endmodule
