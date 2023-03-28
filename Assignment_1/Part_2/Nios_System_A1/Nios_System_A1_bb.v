
module Nios_System_A1 (
	button_pio_external_connection_export,
	clocks_ref_clk_clk,
	clocks_ref_reset_reset,
	clocks_sdram_clk_clk,
	led_pio_external_connection_export,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	segment_1_pio_external_connection_export,
	segment_2_pio_external_connection_export,
	segment_3_pio_external_connection_export,
	segment_4_pio_external_connection_export,
	switch_pio_external_connection_export);	

	input	[3:0]	button_pio_external_connection_export;
	input		clocks_ref_clk_clk;
	input		clocks_ref_reset_reset;
	output		clocks_sdram_clk_clk;
	output	[7:0]	led_pio_external_connection_export;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[15:0]	sdram_wire_dq;
	output	[1:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	output	[6:0]	segment_1_pio_external_connection_export;
	output	[6:0]	segment_2_pio_external_connection_export;
	output	[6:0]	segment_3_pio_external_connection_export;
	output	[6:0]	segment_4_pio_external_connection_export;
	input	[7:0]	switch_pio_external_connection_export;
endmodule
