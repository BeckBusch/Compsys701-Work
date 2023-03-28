--
library IEEE;
use IEEE.std_logic_1164.all;

entity SIMD_MULTI_Instruction is
   port (dataa, datab : in std_logic_vector(31 downto 0);
         result : out std_logic_vector(31 downto 0)); 
end entity SIMD_MULTI_Instruction;

architecture structure of SIMD_MULTI_Instruction is
	component SIMD_MULTI_HW is
       port (reg_A, reg_B : in std_logic_vector(31 downto 0);
	         reg_C : out std_logic_vector(31 downto 0)); 
    end component SIMD_MULTI_HW;
begin
   C1: SIMD_MULTI_HW port map (reg_A => dataa, reg_B => datab, reg_C => result);
end architecture structure;