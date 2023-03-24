--


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;


entity Nios_Sys_3A is
	port (CLOCK_50 : in std_logic;
		  KEY : in std_logic_vector(1 downto 0);  
		  LEDR : out std_logic_vector(7 downto 0);
		  DRAM_DQ : inout std_logic_vector(15 downto 0);
		  DRAM_ADDR : out std_logic_vector(12 downto 0);
		  DRAM_BA : out std_logic_vector(1 downto 0);
		  DRAM_CAS_N, DRAM_RAS_N, DRAM_CLK : out std_logic;
		  DRAM_CKE, DRAM_CS_N, DRAM_WE_N : out std_logic;
		  DRAM_UDQM, DRAM_LDQM: out std_logic);
end entity Nios_Sys_3A;


architecture Structure of Nios_Sys_3A is
	component Nios_System_3A is
		port (
			led_pio_external_connection_export : out   std_logic_vector(7 downto 0);                     -- export
			button_pio_external_connection_export : in    std_logic_vector(1 downto 0)  := (others => 'X');  -- export
			sdram_wire_addr                    : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                      : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                   : out   std_logic;                                        -- cas_n
			sdram_wire_cke                     : out   std_logic;                                        -- cke
			sdram_wire_cs_n                    : out   std_logic;                                        -- cs_n
			sdram_wire_dq                      : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                     : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_wire_ras_n                   : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                    : out   std_logic;                                        -- we_n
			clocks_sdram_clk_clk               : out   std_logic;                                        -- clk
			clocks_ref_clk_clk                 : in    std_logic                     := 'X';             -- clk
			clocks_ref_reset_reset             : in    std_logic                     := 'X'              -- reset
		);
	end component Nios_System_3A;

begin 
	u0 : component Nios_System_3A
		port map (
			led_pio_external_connection_export => LEDR, -- led_pio_external_connection.export
			button_pio_external_connection_export => KEY, -- button_pio_external_connection_export
			sdram_wire_addr                    => DRAM_ADDR,                    --                  sdram_wire.addr
			sdram_wire_ba                      => DRAM_BA,                      --                            .ba
			sdram_wire_cas_n                   => DRAM_CAS_N,                   --                            .cas_n
			sdram_wire_cke                     => DRAM_CKE,                     --                            .cke
			sdram_wire_cs_n                    => DRAM_CS_N,                    --                            .cs_n
			sdram_wire_dq                      => DRAM_DQ,                      --                            .dq
			sdram_wire_dqm(1)                  => DRAM_UDQM,                     --                            .dqm
			sdram_wire_dqm(0)                  => DRAM_LDQM,                     --
			sdram_wire_ras_n                   => DRAM_RAS_N,                   --                            .ras_n
			sdram_wire_we_n                    => DRAM_WE_N,                    --                            .we_n
			clocks_sdram_clk_clk               => DRAM_CLK,               --            clocks_sdram_clk.clk
			clocks_ref_clk_clk                 => CLOCK_50,                 --              clocks_ref_clk.clk
			clocks_ref_reset_reset             => NOT KEY(0)              --            clocks_ref_reset.reset
		);

end architecture Structure;