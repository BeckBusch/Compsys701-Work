-- SIMD_ADD hardware description 
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity SIMD_ADD_HW is
    port (reg_A, reg_B : in std_logic_vector(31 downto 0);
	  reg_C : out std_logic_vector(31 downto 0)); 
end entity SIMD_ADD_HW;

architecture arc_v1 of SIMD_ADD_HW is
begin 
   reg_C(31 downto 24) <= std_logic_vector(unsigned(reg_A(31 downto 24)) + unsigned(reg_B(31 downto 24)));
   reg_C(23 downto 16) <= std_logic_vector(unsigned(reg_A(23 downto 16)) + unsigned(reg_B(23 downto 16)));
   reg_C(15 downto 8) <= std_logic_vector(unsigned(reg_A(15 downto 8)) + unsigned(reg_B(15 downto 8)));
   reg_C(7 downto 0) <= std_logic_vector(unsigned(reg_A(7 downto 0)) + unsigned(reg_B(7 downto 0)));
end architecture arc_v1;