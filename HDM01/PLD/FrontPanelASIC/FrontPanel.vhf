--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : FrontPanel.vhf
-- /___/   /\     Timestamp : 08/10/2017 20:00:08
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
   port ( ECLK   : in    std_logic; 
          MOSI   : in    std_logic; 
          PHA    : in    std_logic; 
          PHB    : in    std_logic; 
          SCLK   : in    std_logic; 
          SS     : in    std_logic; 
          CLK_50 : out   std_logic; 
          DB     : out   std_logic_vector (7 downto 0); 
          DIR    : out   std_logic; 
          IRQ    : out   std_logic; 
          LED_0  : out   std_logic; 
          TP     : out   std_logic);
end FrontPanel;

architecture BEHAVIORAL of FrontPanel is
   attribute BOX_TYPE   : string ;
   attribute SLEW       : string ;
   signal XLXN_1   : std_logic;
   signal XLXN_2   : std_logic;
   signal XLXN_4   : std_logic;
   signal XLXN_5   : std_logic;
   signal XLXN_15  : std_logic;
   signal XLXN_24  : std_logic;
   signal XLXN_26  : std_logic;
   signal DB_DUMMY : std_logic_vector (7 downto 0);
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
   
   component clock_divider
      port ( clk     : in    std_logic; 
             clk_out : out   std_logic);
   end component;
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component spi
      port ( SCLK  : in    std_logic; 
             MOSI  : in    std_logic; 
             SS    : in    std_logic; 
             TFLAG : out   std_logic; 
             PDOUT : out   std_logic_vector (7 downto 0));
   end component;
   
begin
   DB(7 downto 0) <= DB_DUMMY(7 downto 0);
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
   
   XLXI_15 : clock_divider
      port map (clk=>XLXN_15,
                clk_out=>XLXN_26);
   
   XLXI_16 : OBUF
      port map (I=>XLXN_26,
                O=>CLK_50);
   
   XLXI_18 : AND2
      port map (I0=>DB_DUMMY(0),
                I1=>XLXN_26,
                O=>XLXN_24);
   
   XLXI_19 : OBUF
      port map (I=>XLXN_24,
                O=>LED_0);
   
   XLXI_20 : spi
      port map (MOSI=>MOSI,
                SCLK=>SCLK,
                SS=>SS,
                PDOUT(7 downto 0)=>DB_DUMMY(7 downto 0),
                TFLAG=>TP);
   
end BEHAVIORAL;


