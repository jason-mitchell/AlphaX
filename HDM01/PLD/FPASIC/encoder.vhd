--
-- Reference design - Rotary encoder and simple LEDs on Spartan-3E Starter Kit (Revision C)
--
--
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
entity encoder is
    Port (          detent : out std_logic;
						     dir : out std_logic;
						rotary_a : in std_logic;
                  rotary_b : in std_logic;
                       clk : in std_logic);
    end encoder;
--
------------------------------------------------------------------------------------
--
-- Start of test architecture
--
architecture Behavioral of encoder is
--
------------------------------------------------------------------------------------
--
-- Signals used to interface to rotary encoder
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
-- Signals for outputs
--
signal internal_detent : std_logic;
signal internal_direction : std_logic;
--
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--
-- Start of circuit description
--
begin
  --
  ----------------------------------------------------------------------------------------------------------------------------------
  -- Interface to rotary encoder.
  -- Detection of movement and direction.
  ----------------------------------------------------------------------------------------------------------------------------------
  --
  -- The rotary switch contacts are filtered using their offset (one-hot) style to  
  -- clean them. Circuit concept by Peter Alfke.
  -- Note that the clock rate is fast compared with the switch rate.

  rotary_filter: process(clk)
  begin
    if clk'event and clk='1' then

      --Synchronise inputs to clock domain using flip-flops in input/output blocks.
      rotary_a_in <= rotary_a;
      rotary_b_in <= rotary_b;						-- when clock input is high, the signals are all latched i.e. sampled.
      --rotary_press_in <= rotary_press;

      --concatinate rotary input signals to form vector for case construct.
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
  --
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
  --
  --
  ----------------------------------------------------------------------------------------------------------------------------------
  -- LED control.
  ----------------------------------------------------------------------------------------------------------------------------------
  --
  -- The LED pattern is provided by a shift register which has been initialised in the signal 
  -- definition to have only one bit active (High). 
  --
  led_display: process(clk)
  begin
  
    if clk'event and clk='1' then
	 
				if rotary_event='1' then
						--internal_detent <= '1';
						if rotary_left='1' then
							internal_direction <= '1';
						else 							-- without this, rotary_event and rotary_left become invalidated by the compiler NB
							internal_direction <= '0';
						end if;
						internal_detent <= '1';
				else 
                  internal_detent <='0';				
				end if;	
				detent <= internal_detent;			-- detent is updated AFTER direction is stable
    end if;
	 
  end process led_display;
  				dir <= internal_direction;			-- direction is updated BEFORE detent
  --
  --
end Behavioral;

------------------------------------------------------------------------------------------------------------------------------------
--
-- END OF FILE left_right_leds.vhd
--
------------------------------------------------------------------------------------------------------------------------------------



