--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : FrontPanel.vhf
-- /___/   /\     Timestamp : 08/09/2017 17:24:24
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family xc9500xl -flat -suppress -vhdl C:/Temp/Work/AlphaX/HDM01/PLD/FrontPanelASIC/FrontPanel.vhf -w C:/Temp/Work/AlphaX/HDM01/PLD/FrontPanelASIC/FrontPanel.sch
--Design Name: FrontPanel
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

entity FrontPanel is
   port ( ECLK : in    std_logic; 
          MOSI : in    std_logic; 
          PHA  : in    std_logic; 
          PHB  : in    std_logic; 
          SCLK : in    std_logic; 
          DB   : out   std_logic_vector (7 downto 0); 
          DIR  : out   std_logic; 
          IRQ  : out   std_logic);
end FrontPanel;

architecture BEHAVIORAL of FrontPanel is
   attribute BOX_TYPE   : string ;
   attribute SLEW       : string ;
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_4  : std_logic;
   signal XLXN_5  : std_logic;
   signal XLXN_15 : std_logic;
   component rotary_decoder
      port ( rotary_a : in    std_logic; 
             rotary_b : in    std_logic; 
             clk      : in    std_logic; 
             detent   : out   std_logic; 
             dir      : out   std_logic);
   end component;
   
   component IBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of IBUF : component is "BLACK_BOX";
   
   component OBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute SLEW of OBUF : component is "SLOW";
   attribute BOX_TYPE of OBUF : component is "BLACK_BOX";
   
   component spi
      port ( SCLK  : in    std_logic; 
             MOSI  : in    std_logic; 
             PDOUT : out   std_logic_vector (7 downto 0));
   end component;
   
begin
   XLXI_2 : rotary_decoder
      port map (clk=>XLXN_15,
                rotary_a=>XLXN_1,
                rotary_b=>XLXN_2,
                detent=>XLXN_4,
                dir=>XLXN_5);
   
   XLXI_3 : IBUF
      port map (I=>PHA,
                O=>XLXN_1);
   
   XLXI_4 : IBUF
      port map (I=>PHB,
                O=>XLXN_2);
   
   XLXI_5 : IBUF
      port map (I=>ECLK,
                O=>XLXN_15);
   
   XLXI_6 : OBUF
      port map (I=>XLXN_4,
                O=>IRQ);
   
   XLXI_7 : OBUF
      port map (I=>XLXN_5,
                O=>DIR);
   
   XLXI_14 : spi
      port map (MOSI=>MOSI,
                SCLK=>SCLK,
                PDOUT(7 downto 0)=>DB(7 downto 0));
   
end BEHAVIORAL;


