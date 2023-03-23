	component Nios_Sys_3A is
		port (
			button_pio_external_connection_export : in    std_logic_vector(1 downto 0)  := (others => 'X'); -- export
			clocks_ref_clk_clk                    : in    std_logic                     := 'X';             -- clk
			clocks_ref_reset_reset                : in    std_logic                     := 'X';             -- reset
			clocks_sdram_clk_clk                  : out   std_logic;                                        -- clk
			led_pio_external_connection_export    : out   std_logic_vector(7 downto 0);                     -- export
			sdram_wire_addr                       : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                         : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                      : out   std_logic;                                        -- cas_n
			sdram_wire_cke                        : out   std_logic;                                        -- cke
			sdram_wire_cs_n                       : out   std_logic;                                        -- cs_n
			sdram_wire_dq                         : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                        : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_wire_ras_n                      : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                       : out   std_logic                                         -- we_n
		);
	end component Nios_Sys_3A;

	u0 : component Nios_Sys_3A
		port map (
			button_pio_external_connection_export => CONNECTED_TO_button_pio_external_connection_export, -- button_pio_external_connection.export
			clocks_ref_clk_clk                    => CONNECTED_TO_clocks_ref_clk_clk,                    --                 clocks_ref_clk.clk
			clocks_ref_reset_reset                => CONNECTED_TO_clocks_ref_reset_reset,                --               clocks_ref_reset.reset
			clocks_sdram_clk_clk                  => CONNECTED_TO_clocks_sdram_clk_clk,                  --               clocks_sdram_clk.clk
			led_pio_external_connection_export    => CONNECTED_TO_led_pio_external_connection_export,    --    led_pio_external_connection.export
			sdram_wire_addr                       => CONNECTED_TO_sdram_wire_addr,                       --                     sdram_wire.addr
			sdram_wire_ba                         => CONNECTED_TO_sdram_wire_ba,                         --                               .ba
			sdram_wire_cas_n                      => CONNECTED_TO_sdram_wire_cas_n,                      --                               .cas_n
			sdram_wire_cke                        => CONNECTED_TO_sdram_wire_cke,                        --                               .cke
			sdram_wire_cs_n                       => CONNECTED_TO_sdram_wire_cs_n,                       --                               .cs_n
			sdram_wire_dq                         => CONNECTED_TO_sdram_wire_dq,                         --                               .dq
			sdram_wire_dqm                        => CONNECTED_TO_sdram_wire_dqm,                        --                               .dqm
			sdram_wire_ras_n                      => CONNECTED_TO_sdram_wire_ras_n,                      --                               .ras_n
			sdram_wire_we_n                       => CONNECTED_TO_sdram_wire_we_n                        --                               .we_n
		);

