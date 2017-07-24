--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : TLD.vhf
-- /___/   /\     Timestamp : 07/24/2017 20:26:46
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family xc9500xl -flat -suppress -vhdl C:/Temp/Work/AlphaX/HDM01/PLD/FPASIC/TLD.vhf -w C:/Temp/Work/AlphaX/HDM01/PLD/FPASIC/TLD.sch
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

entity FD_MXILINX_TLD is
   generic( INIT : bit :=  '0');
   port ( C : in    std_logic; 
          D : in    std_logic; 
          Q : out   std_logic);
end FD_MXILINX_TLD;

architecture BEHAVIORAL of FD_MXILINX_TLD is
   attribute BOX_TYPE   : string ;
   signal XLXN_4 : std_logic;
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component FDCP
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CLR : in    std_logic; 
             D   : in    std_logic; 
             PRE : in    std_logic; 
             Q   : out   std_logic);
   end component;
   attribute BOX_TYPE of FDCP : component is "BLACK_BOX";
   
begin
   I_36_43 : GND
      port map (G=>XLXN_4);
   
   U0 : FDCP
   generic map( INIT => INIT)
      port map (C=>C,
                CLR=>XLXN_4,
                D=>D,
                PRE=>XLXN_4,
                Q=>Q);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity TLD is
   port ( clock     : in    std_logic; 
          pha       : in    std_logic; 
          phb       : in    std_logic; 
          DATA      : out   std_logic; 
          direction : out   std_logic; 
          ticks     : out   std_logic);
end TLD;

architecture BEHAVIORAL of TLD is
   attribute HU_SET     : string ;
   attribute BOX_TYPE   : string ;
   signal XLXN_1      : std_logic;
   signal XLXN_3      : std_logic;
   signal ticks_DUMMY : std_logic;
   component encoder
      port ( rotary_a : in    std_logic; 
             rotary_b : in    std_logic; 
             clk      : in    std_logic; 
             detent   : out   std_logic; 
             dir      : out   std_logic);
   end component;
   
   component FD_MXILINX_TLD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component BUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of BUF : component is "BLACK_BOX";
   
   attribute HU_SET of XLXI_2 : label is "XLXI_2_0";
begin
   ticks <= ticks_DUMMY;
   XLXI_1 : encoder
      port map (clk=>clock,
                rotary_a=>pha,
                rotary_b=>phb,
                detent=>ticks_DUMMY,
                dir=>direction);
   
   XLXI_2 : FD_MXILINX_TLD
      port map (C=>ticks_DUMMY,
                D=>XLXN_3,
                Q=>XLXN_1);
   
   XLXI_3 : INV
      port map (I=>XLXN_1,
                O=>XLXN_3);
   
   XLXI_4 : BUF
      port map (I=>XLXN_1,
                O=>DATA);
   
end BEHAVIORAL;


