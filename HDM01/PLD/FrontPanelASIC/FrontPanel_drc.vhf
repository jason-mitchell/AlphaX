--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : FrontPanel_drc.vhf
-- /___/   /\     Timestamp : 08/13/2017 16:15:00
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: C:\Xilinx\14.7\ISE_DS\ISE\bin\nt64\unwrapped\sch2hdl.exe -intstyle ise -family xc9500xl -flat -suppress -vhdl FrontPanel_drc.vhf -w C:/Temp/Work/AlphaX/HDM01/PLD/FrontPanelASIC/FrontPanel.sch
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

entity FD_MXILINX_FrontPanel is
   generic( INIT : bit :=  '0');
   port ( C : in    std_logic; 
          D : in    std_logic; 
          Q : out   std_logic);
end FD_MXILINX_FrontPanel;

architecture BEHAVIORAL of FD_MXILINX_FrontPanel is
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

entity FrontPanel is
   port ( ECLK   : in    std_logic; 
          IN0    : in    std_logic; 
          IN1    : in    std_logic; 
          IN2    : in    std_logic; 
          IN3    : in    std_logic; 
          MOSI   : in    std_logic; 
          PHA    : in    std_logic; 
          PHB    : in    std_logic; 
          RESET  : in    std_logic; 
          SCLK   : in    std_logic; 
          SS     : in    std_logic; 
          CLK_50 : out   std_logic; 
          DIR    : out   std_logic; 
          IRQ    : out   std_logic; 
          LED_0  : out   std_logic; 
          LED_1  : out   std_logic; 
          LED_2  : out   std_logic; 
          LED_3  : out   std_logic; 
          LED_4  : out   std_logic; 
          LED_5  : out   std_logic; 
          LED_6  : out   std_logic; 
          LED_7  : out   std_logic; 
          MISO   : out   std_logic);
end FrontPanel;

architecture BEHAVIORAL of FrontPanel is
   attribute BOX_TYPE   : string ;
   attribute SLEW       : string ;
   attribute HU_SET     : string ;
   signal INPUT   : std_logic_vector (7 downto 0);
   signal LED     : std_logic_vector (7 downto 0);
   signal XLXN_1  : std_logic;
   signal XLXN_2  : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_24 : std_logic;
   signal XLXN_27 : std_logic;
   signal XLXN_28 : std_logic;
   signal XLXN_29 : std_logic;
   signal XLXN_30 : std_logic;
   signal XLXN_31 : std_logic;
   signal XLXN_32 : std_logic;
   signal XLXN_33 : std_logic;
   signal XLXN_41 : std_logic;
   signal XLXN_56 : std_logic;
   signal XLXN_61 : std_logic;
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
      port ( SCLK      : in    std_logic; 
             MOSI      : in    std_logic; 
             SS        : in    std_logic; 
             NRST      : in    std_logic; 
             INPUTPORT : in    std_logic_vector (7 downto 0); 
             MISO      : out   std_logic; 
             TFLAG     : out   std_logic; 
             LEDPORT   : out   std_logic_vector (7 downto 0); 
             PWMPORT   : out   std_logic_vector (7 downto 0));
   end component;
   
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component FD_MXILINX_FrontPanel
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
   
   attribute HU_SET of XLXI_41 : label is "XLXI_41_0";
begin
   XLXI_2 : rotary_decoder
      port map (clk=>XLXN_15,
                rotary_a=>XLXN_1,
                rotary_b=>XLXN_2,
                detent=>XLXN_61,
                dir=>INPUT(4));
   
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
      port map (I=>XLXN_61,
                O=>IRQ);
   
   XLXI_7 : OBUF
      port map (I=>INPUT(4),
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
   
   XLXI_22 : AND2
      port map (I0=>LED(3),
                I1=>XLXN_41,
                O=>XLXN_29);
   
   XLXI_23 : AND2
      port map (I0=>LED(4),
                I1=>XLXN_41,
                O=>XLXN_30);
   
   XLXI_24 : AND2
      port map (I0=>LED(5),
                I1=>XLXN_41,
                O=>XLXN_31);
   
   XLXI_25 : AND2
      port map (I0=>LED(6),
                I1=>XLXN_41,
                O=>XLXN_32);
   
   XLXI_26 : AND2
      port map (I0=>LED(7),
                I1=>XLXN_41,
                O=>XLXN_33);
   
   XLXI_27 : OBUF
      port map (I=>XLXN_27,
                O=>LED_1);
   
   XLXI_28 : OBUF
      port map (I=>XLXN_28,
                O=>LED_2);
   
   XLXI_29 : OBUF
      port map (I=>XLXN_29,
                O=>LED_3);
   
   XLXI_30 : OBUF
      port map (I=>XLXN_30,
                O=>LED_4);
   
   XLXI_31 : OBUF
      port map (I=>XLXN_31,
                O=>LED_5);
   
   XLXI_32 : OBUF
      port map (I=>XLXN_32,
                O=>LED_6);
   
   XLXI_33 : OBUF
      port map (I=>XLXN_33,
                O=>LED_7);
   
   XLXI_34 : spi
      port map (INPUTPORT(7 downto 0)=>INPUT(7 downto 0),
                MOSI=>MOSI,
                NRST=>RESET,
                SCLK=>SCLK,
                SS=>SS,
                LEDPORT(7 downto 0)=>LED(7 downto 0),
                MISO=>MISO,
                PWMPORT=>open,
                TFLAG=>open);
   
   XLXI_35 : GND
      port map (G=>INPUT(7));
   
   XLXI_36 : GND
      port map (G=>INPUT(6));
   
   XLXI_37 : IBUF
      port map (I=>IN0,
                O=>INPUT(0));
   
   XLXI_38 : IBUF
      port map (I=>IN1,
                O=>INPUT(1));
   
   XLXI_39 : IBUF
      port map (I=>IN2,
                O=>INPUT(2));
   
   XLXI_40 : IBUF
      port map (I=>IN3,
                O=>INPUT(3));
   
   XLXI_41 : FD_MXILINX_FrontPanel
      port map (C=>XLXN_61,
                D=>XLXN_56,
                Q=>INPUT(5));
   
   XLXI_42 : INV
      port map (I=>INPUT(5),
                O=>XLXN_56);
   
end BEHAVIORAL;


