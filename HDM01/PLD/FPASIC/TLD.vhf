--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : TLD.vhf
-- /___/   /\     Timestamp : 07/31/2017 00:12:29
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

entity COMP4_MXILINX_TLD is
   port ( A0 : in    std_logic; 
          A1 : in    std_logic; 
          A2 : in    std_logic; 
          A3 : in    std_logic; 
          B0 : in    std_logic; 
          B1 : in    std_logic; 
          B2 : in    std_logic; 
          B3 : in    std_logic; 
          EQ : out   std_logic);
end COMP4_MXILINX_TLD;

architecture BEHAVIORAL of COMP4_MXILINX_TLD is
   attribute BOX_TYPE   : string ;
   signal AB0 : std_logic;
   signal AB1 : std_logic;
   signal AB2 : std_logic;
   signal AB3 : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component XNOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XNOR2 : component is "BLACK_BOX";
   
begin
   I_36_32 : AND4
      port map (I0=>AB3,
                I1=>AB2,
                I2=>AB1,
                I3=>AB0,
                O=>EQ);
   
   I_36_33 : XNOR2
      port map (I0=>B2,
                I1=>A2,
                O=>AB2);
   
   I_36_34 : XNOR2
      port map (I0=>B3,
                I1=>A3,
                O=>AB3);
   
   I_36_42 : XNOR2
      port map (I0=>B1,
                I1=>A1,
                O=>AB1);
   
   I_36_43 : XNOR2
      port map (I0=>B0,
                I1=>A0,
                O=>AB0);
   
end BEHAVIORAL;



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

entity FTCE_MXILINX_TLD is
   generic( INIT : bit :=  '0');
   port ( C   : in    std_logic; 
          CE  : in    std_logic; 
          CLR : in    std_logic; 
          T   : in    std_logic; 
          Q   : out   std_logic);
end FTCE_MXILINX_TLD;

architecture BEHAVIORAL of FTCE_MXILINX_TLD is
   attribute BOX_TYPE       : string ;
   signal TQ      : std_logic;
   signal Q_DUMMY : std_logic;
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
   component FDCE
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             D   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   attribute BOX_TYPE of FDCE : component is "BLACK_BOX";
   
begin
   Q <= Q_DUMMY;
   I_36_32 : XOR2
      port map (I0=>T,
                I1=>Q_DUMMY,
                O=>TQ);
   
   I_36_35 : FDCE
   generic map( INIT => INIT)
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                D=>TQ,
                Q=>Q_DUMMY);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity CB4CE_MXILINX_TLD is
   port ( C   : in    std_logic; 
          CE  : in    std_logic; 
          CLR : in    std_logic; 
          CEO : out   std_logic; 
          Q0  : out   std_logic; 
          Q1  : out   std_logic; 
          Q2  : out   std_logic; 
          Q3  : out   std_logic; 
          TC  : out   std_logic);
end CB4CE_MXILINX_TLD;

architecture BEHAVIORAL of CB4CE_MXILINX_TLD is
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal T2       : std_logic;
   signal T3       : std_logic;
   signal XLXN_1   : std_logic;
   signal Q0_DUMMY : std_logic;
   signal Q1_DUMMY : std_logic;
   signal Q2_DUMMY : std_logic;
   signal Q3_DUMMY : std_logic;
   signal TC_DUMMY : std_logic;
   component AND4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND4 : component is "BLACK_BOX";
   
   component AND3
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND3 : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component FTCE_MXILINX_TLD
      generic( INIT : bit :=  '0');
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             T   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   
   attribute HU_SET of U0 : label is "U0_0";
   attribute HU_SET of U1 : label is "U1_1";
   attribute HU_SET of U2 : label is "U2_2";
   attribute HU_SET of U3 : label is "U3_3";
begin
   Q0 <= Q0_DUMMY;
   Q1 <= Q1_DUMMY;
   Q2 <= Q2_DUMMY;
   Q3 <= Q3_DUMMY;
   TC <= TC_DUMMY;
   I_36_31 : AND4
      port map (I0=>Q3_DUMMY,
                I1=>Q2_DUMMY,
                I2=>Q1_DUMMY,
                I3=>Q0_DUMMY,
                O=>TC_DUMMY);
   
   I_36_32 : AND3
      port map (I0=>Q2_DUMMY,
                I1=>Q1_DUMMY,
                I2=>Q0_DUMMY,
                O=>T3);
   
   I_36_33 : AND2
      port map (I0=>Q1_DUMMY,
                I1=>Q0_DUMMY,
                O=>T2);
   
   I_36_58 : VCC
      port map (P=>XLXN_1);
   
   I_36_67 : AND2
      port map (I0=>CE,
                I1=>TC_DUMMY,
                O=>CEO);
   
   U0 : FTCE_MXILINX_TLD
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                T=>XLXN_1,
                Q=>Q0_DUMMY);
   
   U1 : FTCE_MXILINX_TLD
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                T=>Q0_DUMMY,
                Q=>Q1_DUMMY);
   
   U2 : FTCE_MXILINX_TLD
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                T=>T2,
                Q=>Q2_DUMMY);
   
   U3 : FTCE_MXILINX_TLD
      port map (C=>C,
                CE=>CE,
                CLR=>CLR,
                T=>T3,
                Q=>Q3_DUMMY);
   
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
          pwm0      : in    std_logic; 
          pwm1      : in    std_logic; 
          pwm2      : in    std_logic; 
          pwm3      : in    std_logic; 
          direction : out   std_logic; 
          muxout    : out   std_logic; 
          ticks     : out   std_logic);
end TLD;

architecture BEHAVIORAL of TLD is
   attribute SLEW       : string ;
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal XLXN_14   : std_logic;
   signal XLXN_15   : std_logic;
   signal XLXN_17   : std_logic;
   signal XLXN_18   : std_logic;
   signal XLXN_25   : std_logic;
   signal XLXN_60   : std_logic;
   signal XLXN_61   : std_logic;
   signal XLXN_62   : std_logic;
   signal XLXN_72   : std_logic;
   signal XLXN_74   : std_logic;
   signal XLXN_83   : std_logic;
   signal XLXN_89   : std_logic;
   signal XLXN_93   : std_logic;
   signal XLXN_94   : std_logic;
   signal XLXN_95   : std_logic;
   signal XLXN_98   : std_logic;
   signal XLXN_99   : std_logic;
   signal XLXN_103  : std_logic;
   signal XLXN_104  : std_logic;
   signal XLXN_105  : std_logic;
   signal XLXN_108  : std_logic;
   component encoder
      port ( rotary_a : in    std_logic; 
             rotary_b : in    std_logic; 
             clk      : in    std_logic; 
             detent   : out   std_logic; 
             dir      : out   std_logic);
   end component;
   
   component OBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute SLEW of OBUF : component is "SLOW";
   attribute BOX_TYPE of OBUF : component is "BLACK_BOX";
   
   component IBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of IBUF : component is "BLACK_BOX";
   
   component CB4CE_MXILINX_TLD
      port ( C   : in    std_logic; 
             CE  : in    std_logic; 
             CLR : in    std_logic; 
             CEO : out   std_logic; 
             Q0  : out   std_logic; 
             Q1  : out   std_logic; 
             Q2  : out   std_logic; 
             Q3  : out   std_logic; 
             TC  : out   std_logic);
   end component;
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component COMP4_MXILINX_TLD
      port ( A0 : in    std_logic; 
             A1 : in    std_logic; 
             A2 : in    std_logic; 
             A3 : in    std_logic; 
             B0 : in    std_logic; 
             B1 : in    std_logic; 
             B2 : in    std_logic; 
             B3 : in    std_logic; 
             EQ : out   std_logic);
   end component;
   
   component OR4
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR4 : component is "BLACK_BOX";
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component FD_MXILINX_TLD
      generic( INIT : bit :=  '0');
      port ( C : in    std_logic; 
             D : in    std_logic; 
             Q : out   std_logic);
   end component;
   
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
   attribute HU_SET of XLXI_13 : label is "XLXI_13_4";
   attribute HU_SET of XLXI_16 : label is "XLXI_16_5";
   attribute HU_SET of XLXI_29 : label is "XLXI_29_6";
   attribute HU_SET of XLXI_31 : label is "XLXI_31_7";
   attribute HU_SET of XLXI_37 : label is "XLXI_37_8";
begin
   XLXI_1 : encoder
      port map (clk=>XLXN_72,
                rotary_a=>XLXN_14,
                rotary_b=>XLXN_15,
                detent=>XLXN_17,
                dir=>XLXN_18);
   
   XLXI_8 : OBUF
      port map (I=>XLXN_18,
                O=>direction);
   
   XLXI_9 : OBUF
      port map (I=>XLXN_17,
                O=>ticks);
   
   XLXI_10 : IBUF
      port map (I=>pha,
                O=>XLXN_14);
   
   XLXI_11 : IBUF
      port map (I=>phb,
                O=>XLXN_15);
   
   XLXI_12 : IBUF
      port map (I=>clock,
                O=>XLXN_72);
   
   XLXI_13 : CB4CE_MXILINX_TLD
      port map (C=>XLXN_72,
                CE=>XLXN_25,
                CLR=>XLXN_98,
                CEO=>open,
                Q0=>XLXN_93,
                Q1=>XLXN_94,
                Q2=>XLXN_95,
                Q3=>XLXN_83,
                TC=>open);
   
   XLXI_15 : VCC
      port map (P=>XLXN_25);
   
   XLXI_16 : COMP4_MXILINX_TLD
      port map (A0=>XLXN_93,
                A1=>XLXN_94,
                A2=>XLXN_95,
                A3=>XLXN_83,
                B0=>pwm0,
                B1=>pwm1,
                B2=>pwm2,
                B3=>pwm3,
                EQ=>XLXN_60);
   
   XLXI_21 : OBUF
      port map (I=>XLXN_62,
                O=>muxout);
   
   XLXI_24 : OR4
      port map (I0=>pwm3,
                I1=>pwm2,
                I2=>pwm1,
                I3=>pwm0,
                O=>XLXN_61);
   
   XLXI_25 : AND2
      port map (I0=>XLXN_61,
                I1=>XLXN_60,
                O=>XLXN_89);
   
   XLXI_29 : FD_MXILINX_TLD
      port map (C=>XLXN_74,
                D=>XLXN_99,
                Q=>XLXN_62);
   
   XLXI_31 : COMP4_MXILINX_TLD
      port map (A0=>XLXN_93,
                A1=>XLXN_94,
                A2=>XLXN_95,
                A3=>XLXN_83,
                B0=>XLXN_108,
                B1=>XLXN_108,
                B2=>XLXN_105,
                B3=>XLXN_108,
                EQ=>XLXN_98);
   
   XLXI_32 : VCC
      port map (P=>XLXN_108);
   
   XLXI_33 : GND
      port map (G=>XLXN_105);
   
   XLXI_36 : XOR2
      port map (I0=>XLXN_89,
                I1=>XLXN_99,
                O=>XLXN_74);
   
   XLXI_37 : COMP4_MXILINX_TLD
      port map (A0=>XLXN_93,
                A1=>XLXN_94,
                A2=>XLXN_95,
                A3=>XLXN_83,
                B0=>XLXN_103,
                B1=>XLXN_104,
                B2=>XLXN_103,
                B3=>XLXN_104,
                EQ=>XLXN_99);
   
   XLXI_39 : GND
      port map (G=>XLXN_103);
   
   XLXI_40 : VCC
      port map (P=>XLXN_104);
   
end BEHAVIORAL;


