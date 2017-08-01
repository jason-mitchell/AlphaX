----------------------------------------------------------------------------------------------------
-- rotary_decoder.vhd
-- A proven, decoder solution in VHDL for rotary encoders (Bourns type)
-- Based on the Xilinx Spartan -3E example project and modified for taste
-- Removed LED drivers and made this a module that is intended to assert an IRQ on a microcontroller
-- Minimum clock for sampling = 500Hz
--
-- Using the Peter Alfke technique 
-- Design concept by the late Peter Alfke- Xilinx (1931 - 2011)
-- Modified to taste to be portable on all Xilinx products (including the XC9536 as a minimum)
--
--                  (c) 2017 That Blue Hedgehog
--                              ______
--	                      _.-*'"      "`*-._
--	                _.-*'                  `*-._
--	             .-'                            `-.
--	  /`-.    .-'                  _.              `-.
--	 :    `..'                  .-'_ .                `.
--	 |    .'                 .-'_.' \ .                 \
--	 |   /                 .' .*     ;               .-'"
--	 :   L                    `.     | ;          .-'
--	  \.' `*.          .-*"*-.  `.   ; |        .'
--	  /      \        '       `.  `-'  ;      .'
--	 : .'"`.  .       .-*'`*-.  \     .      (_
--	 |              .'        \  .             `*-.
--	 |.     .      /           ;                   `-.
--	 :    db      '       d$b  |                      `-.
--	 .   :PT;.   '       :P"T; :                         `.
--	 :   :bd;   '        :b_d; :                           \
--	 |   :$$; `'         :$$$; |                            \
--	 |    TP              T$P  '                             ;
--	 :                        /.-*'"`.                       |
--	.sdP^T$bs.               /'       \
--	$$$._.$$$$b.--._      _.'   .--.   ;
--	`*$$$$$$P*'     `*--*'     '  / \  :
--	   \                        .'   ; ;
--	    `.                  _.-'    ' /
--	      `*-.                      .'
--	          `*-._            _.-*'
--	               `*=--..--=*'
--
--
----------------------------------------------------------------------------------------------------
--
-- Library declarations
--
-- Standard IEEE libraries
--
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
--
------------------------------------------------------------------------------------
--
--
entity rotary_decoder is
    Port (          detent : out std_logic;
						     dir : out std_logic;
						rotary_a : in std_logic;
                  rotary_b : in std_logic;
                       clk : in std_logic);
    end rotary_decoder;
--
------------------------------------------------------------------------------------
-- Architecture of module
------------------------------------------------------------------------------------
architecture Behavioral of rotary_decoder is
--
--
-- Module I/O
--
signal      rotary_a_in : std_logic;
signal      rotary_b_in : std_logic;
signal        rotary_in : std_logic_vector(1 downto 0);
signal        rotary_q1 : std_logic;
signal        rotary_q2 : std_logic;
signal  delay_rotary_q1 : std_logic;
signal     rotary_event : std_logic;
signal      rotary_left : std_logic;
--
-- Internal buffering to guarantee glitch-free output
-- Important if this will fire an IRQ handler on a very fast processor
--
signal internal_detent : std_logic;
signal internal_direction : std_logic;
--
--
--
-----------------------------------------------------------------------------------
-- Circuitry in module
-----------------------------------------------------------------------------------
begin
 
  -------------------------------------------
  -- Filter / Debounce 
  ------------------------------------------

  rotary_filter: process(clk)
  begin
		-- Sample the pha, phb when clock event occurs
    if clk'event and clk='1' then
      rotary_a_in <= rotary_a;
      rotary_b_in <= rotary_b;	

      --concatenate rotary input signals to form vector for case construct.
      rotary_in <= rotary_b_in & rotary_a_in;

      case rotary_in is

        when "00" => rotary_q1 <= '0';         
                     rotary_q2 <= rotary_q2;
 
        when "01" => rotary_q1 <= rotary_q1;
                     rotary_q2 <= '0';

        when "10" => rotary_q1 <= rotary_q1;
                     rotary_q2 <= '1';

        when "11" => rotary_q1 <= '1';
                     rotary_q2 <= rotary_q2; 

        when others => rotary_q1 <= rotary_q1; 
                       rotary_q2 <= rotary_q2; 
      end case;

    end if;
  end process rotary_filter;
  
  --
  -- The rising edges of 'rotary_q1' indicate that a rotation has occurred and the 
  -- state of 'rotary_q2' at that time will indicate the direction. 
 
  direction: process(clk)
  begin
    if clk'event and clk='1' then

      delay_rotary_q1 <= rotary_q1;
      if rotary_q1='1' and delay_rotary_q1='0' then
        rotary_left <= rotary_q2;
		  rotary_event <= '1';
       else
        rotary_left <= rotary_left;
		  rotary_event <= '0';
      end if;

    end if;
  end process direction;
  
  ----------------------------------------------------------------------------------------------------------------------------------
  -- Output Signals to microcontroller or other Top-level modules
  ----------------------------------------------------------------------------------------------------------------------------------
  
  output_signaling: process(clk)
  begin
		if clk'event and clk='1' then
				if rotary_event='1' then
						if rotary_left='1' then
							internal_direction <= '1';
						else 					
							internal_direction <= '0';			
						end if;
						internal_detent <= '1';		-- Double buffering is used here to ensure the output is glitch-free (we're going into the IRQ pin of an ARM Cortex)
				else 
                  internal_detent <='0';				
				end if;	
				detent <= internal_detent;			-- detent is updated AFTER direction is stable
    end if;
	 
  end process output_signaling;
  				dir <= internal_direction;			-- direction is updated BEFORE detent
  --
  --
end Behavioral;

------------------------------------------------------------------------------------------------------------------------------------
--
-- END OF FILE rotary_decoder.vhd
--
------------------------------------------------------------------------------------------------------------------------------------