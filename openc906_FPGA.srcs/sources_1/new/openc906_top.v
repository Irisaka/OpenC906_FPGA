`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/10/15 20:18:03
// Design Name: 
// Module Name: openc906_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module openc906_top(

    input clk_in,
    // input rst_n,

    // input jclk,
    // input jrst_n,
    // input jtg_tms,
    // input jtg_tdi,
    // output jtg_tdo,

    input uart0_sin_rx,
    output uart0_sout_tx

    // inout [7:0] b_pad_gpio_porta

);

reg rst_n = 1;

reg jclk;
reg jrst_n = 1;
reg jtg_tms = 0;
reg jtg_tdi = 0;
wire jtg_tdo;

wire [7:0] b_pad_gpio_porta;

IBUFG clkin_ibuf(
    .O(clk_25m),
    .I(clk_in)
);

clk_wiz_0 sysclk(
    .resetn(rst_n),
    .clk_in1(clk_25m),
    .clk_out1(clk_100m),
    .locked()
);

soc x_soc(
    .i_pad_clk           ( clk_100m                  ),
    .b_pad_gpio_porta    ( b_pad_gpio_porta     ),
    .i_pad_jtg_trst_b    ( jrst_n               ),
    .i_pad_jtg_nrst_b    ( rst_n                ),
    .i_pad_jtg_tclk      ( jclk                 ),
    .i_pad_jtg_tdi       ( jtg_tdi              ),
    .i_pad_jtg_tms       ( jtg_tms              ),
    .i_pad_uart0_sin     ( uart0_sin_rx            ),
    .o_pad_jtg_tdo       ( jtg_tdo              ),
    .o_pad_uart0_sout    ( uart0_sout_tx           ),
    .i_pad_rst_b         ( rst_n                )
);

endmodule
