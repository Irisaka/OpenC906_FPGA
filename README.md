# OpenC906 on FPGA

Github: https://github.com/Irisaka/OpenC906_FPGA

Based on https://github.com/XUANTIE-RV/openc906, we get **RISC-V SoC (core C906)**  running on **Xilinx FPGA (Kintex-7 xc7k325tfbg900)**. 

The Vivado (2018.2) Project is presented, in conjunction with the behavioral simulation platform on WSL (https://github.com/Irisaka/OpenC906_WSL_SIM)

## Features

* Without JTAG device (eg. CK-Link), C906 can run C language programs from initialized RAMs in FPGA.
* The BRAM usage of SoC is adjusted to fit FPGA xc7k325tfbg900.
* The UART peripheral has been tested to work properly, and the running status of C906 can be output by adjusting the C language program.

## Brief Process

#### Step 1: Create Vivado project and add source code

Verilog source code files are in these directories:

```
|--C906_RTL_FACRORY/
  |--gen_rtl/
|--smart_run/
  |--logical/
```

The following need to be listed as global include files.

```verilog
`include "aq_dtu_cfig.h"
`include "aq_idu_cfig.h"
`include "aq_lsu_cfig.h"
`include "cpu_cfig.h"
`include "sysmap.h"
`include "tdt_define.h"
`include "tdt_dmi_define.h"
```

#### Step 2: Create top module, clock source and .xdc constraint file

Only three signals are led out, which means that most boards can implement this design. In .xdc file, the specific pin position needs to be determined according to the circuit board design.

```verilog
// Top module
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

clk_wiz_0 sysclk(      // using vivado IP
    .resetn(rst_n),
    .clk_in1(clk_25m),
    .clk_out1(clk_100m),
    .locked()
);

soc x_soc(
    .i_pad_clk           ( clk_100m             ),
    .b_pad_gpio_porta    ( b_pad_gpio_porta     ),
    .i_pad_jtg_trst_b    ( jrst_n               ),
    .i_pad_jtg_nrst_b    ( rst_n                ),
    .i_pad_jtg_tclk      ( jclk                 ),
    .i_pad_jtg_tdi       ( jtg_tdi              ),
    .i_pad_jtg_tms       ( jtg_tms              ),
    .i_pad_uart0_sin     ( uart0_sin_rx         ),
    .o_pad_jtg_tdo       ( jtg_tdo              ),
    .o_pad_uart0_sout    ( uart0_sout_tx        ),
    .i_pad_rst_b         ( rst_n                )
);
endmodule
```

#### Step 3: Generate RAM initialization files

Follow the guide of simulation platform (https://github.com/Irisaka/OpenC906_WSL_SIM), use GCC toolchain and Matlab script to generate splitted machine code files.

When FPGA starts up, 16 internal RAMs will use $readmemh to read machine code, booting C906 running C language programs.

```verilog
// upper module
init_ram #(
  .DATAWIDTH(WRAP_WIDTH),
  .ADDRWIDTH(ADDR_WIDTH),
  .INIT_FILE("Your Path/ram0_init.txt")
) ram0 (
  .PortAClk (CLK),
  .PortAAddr(addr),
  .PortADataIn (ram0_din),
  .PortAWriteEnable(ram0_wen),
  .PortADataOut(ram0_dout)
);

// in init_ram module
initial begin
    if (INIT_FILE != "") begin
        $readmemh(INIT_FILE, mem);
    end
end
```

#### Step 4: Run Vivado workflow

After all set, go through synthesis, implementation and bitstream generation in vivado, then get C906 running on FPGA!