-- SIMD_ADD hardware description 
-- test comment
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity SIMD_MULTI_HW is
    port (reg_A, reg_B : in std_logic_vector(31 downto 0);
	  reg_C : out std_logic_vector(31 downto 0)); 
end entity SIMD_MULTI_HW;

architecture arc_v1 of SIMD_MULTI_HW is
begin 
   reg_C(31 downto 16) <= std_logic_vector(unsigned(reg_A(31 downto 16)) * unsigned(reg_B(31 downto 16)))(15 downto 0);
   reg_C(15 downto 0) <= std_logic_vector(unsigned(reg_A(15 downto 0)) * unsigned(reg_B(15 downto 0)))(15 downto 0);
end architecture arc_v1;