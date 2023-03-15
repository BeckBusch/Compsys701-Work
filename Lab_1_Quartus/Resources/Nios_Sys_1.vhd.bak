-- Top level  

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Nios_Sys_1 is
	port (CLOCK_50 : in std_logic;
		  KEY : in std_logic_vector(0 to 0);  -- Note here for reset
		  LEDR : out std_logic_vector(7 downto 0));
end entity Nios_Sys_1;

architecture structure of Nios_Sys_1 is
	component Nios_V1 is
		port (
			clk_clk                            : in  std_logic                    := 'X'; -- clk
			reset_reset_n                      : in  std_logic                    := 'X'; -- reset_n
			led_pio_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component Nios_V1;
	
	
begin 
	u0 : component Nios_V1
		port map (
			clk_clk                            => CLOCK_50,
			reset_reset_n                      => KEY(0),
			led_pio_external_connection_export => LEDR
		);
end architecture structure;