--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : TLD_drc.vhf
-- /___/   /\     Timestamp : 07/24/2017 19:49:30
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: C:\Xilinx\14.7\ISE_DS\ISE\bin\nt64\unwrapped\sch2hdl.exe -intstyle ise -family xc9500xl -flat -suppress -vhdl TLD_drc.vhf -w C:/Temp/Work/AlphaX/HDM01/PLD/FPASIC/TLD.sch
--Design Name: TLD
--Device: xc9500xl
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity TLD is
   port ( clock     : in    std_logic; 
          pha       : in    std_logic; 
          phb       : in    std_logic; 
          direction : out   std_logic; 
          ticks     : out   std_logic);
end TLD;

architecture BEHAVIORAL of TLD is
   component encoder
      port ( rotary_a : in    std_logic; 
             rotary_b : in    std_logic; 
             clk      : in    std_logic; 
             detent   : out   std_logic; 
             dir      : out   std_logic);
   end component;
   
begin
   XLXI_1 : encoder
      port map (clk=>clock,
                rotary_a=>pha,
                rotary_b=>phb,
                detent=>ticks,
                dir=>direction);
   
end BEHAVIORAL;


