--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : FrontPanel.vhf
-- /___/   /\     Timestamp : 08/20/2017 17:28:10
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
   port ( ECLK    : in    std_logic; 
          MOSI    : in    std_logic; 
          PHA     : in    std_logic; 
          PHB     : in    std_logic; 
          RESET   : in    std_logic; 
          SCLK    : in    std_logic; 
          SS      : in    std_logic; 
          BYTE_IN : out   std_logic; 
          CLK_50  : out   std_logic; 
          DIR     : out   std_logic; 
          IRQ     : out   std_logic; 
          LED_0   : out   std_logic; 
          LED_1   : out   std_logic; 
          LED_2   : out   std_logic; 
          MISO    : out   std_logic);
end FrontPanel;

architecture BEHAVIORAL of FrontPanel is
   attribute BOX_TYPE   : string ;
   attribute SLEW       : string ;
   signal LED     : std_logic_vector (7 downto 0);
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_24 : std_logic;
   signal XLXN_27 : std_logic;
   signal XLXN_28 : std_logic;
   signal XLXN_41 : std_logic;
   signal XLXN_66 : std_logic;
   signal XLXN_77 : std_logic;
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
      port ( SCLK    : in    std_logic; 
             MOSI    : in    std_logic; 
             SS      : in    std_logic; 
             NRST    : in    std_logic; 
             MISO    : out   std_logic; 
             LEDPORT : out   std_logic_vector (7 downto 0); 
             BYTE_IN : out   std_logic);
   end component;
   
begin
   XLXI_2 : rotary_decoder
      port map (clk=>XLXN_15,
                rotary_a=>XLXN_1,
                rotary_b=>XLXN_2,
                detent=>XLXN_66,
                dir=>XLXN_77);
   
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
      port map (I=>XLXN_66,
                O=>IRQ);
   
   XLXI_7 : OBUF
      port map (I=>XLXN_77,
                O=>DIR);
   
   XLXI_15 : clock_divider
      port map (clk=>XLXN_15,
                clk_out=>XLXN_41);
   
   XLXI_16 : OBUF
      port map (I=>XLXN_41,
                O=>CLK_50);
   
   XLXI_18 : AND2
      port map (I0=>LED(0),
                I1=>XLXN_41,
                O=>XLXN_24);
   
   XLXI_19 : OBUF
      port map (I=>XLXN_24,
                O=>LED_0);
   
   XLXI_20 : AND2
      port map (I0=>LED(1),
                I1=>XLXN_41,
                O=>XLXN_27);
   
   XLXI_21 : AND2
      port map (I0=>LED(2),
                I1=>XLXN_41,
                O=>XLXN_28);
   
   XLXI_27 : OBUF
      port map (I=>XLXN_27,
                O=>LED_1);
   
   XLXI_28 : OBUF
      port map (I=>XLXN_28,
                O=>LED_2);
   
   XLXI_29 : spi
      port map (MOSI=>MOSI,
                NRST=>RESET,
                SCLK=>SCLK,
                SS=>SS,
                BYTE_IN=>BYTE_IN,
                LEDPORT(7 downto 0)=>LED(7 downto 0),
                MISO=>MISO);
   
end BEHAVIORAL;


