/*Copyright 2020-2021 T-Head Semiconductor Co., Ltd.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

// ADDR is 28-bit, 4K address
// Flag includes: Strong Order, Cacheable, Bufferable, Shareable, Security

  // `define SYSMAP_BASE_ADDR0  28'h8ffff
  // // `define SYSMAP_FLG0        5'b01111
  // `define SYSMAP_FLG0        5'b00111
  
  // `define SYSMAP_BASE_ADDR1  28'hbffff
  // `define SYSMAP_FLG1        5'b10011
  
  // `define SYSMAP_BASE_ADDR2  28'hcffff
  // `define SYSMAP_FLG2        5'b00011
  
  // `define SYSMAP_BASE_ADDR3  28'heffff
  // `define SYSMAP_FLG3        5'b01101
  
  // `define SYSMAP_BASE_ADDR4  28'hfffff
  // `define SYSMAP_FLG4        5'b01111
  
  // `define SYSMAP_BASE_ADDR5  28'h3ffffff
  // `define SYSMAP_FLG5        5'b01111
  
  // `define SYSMAP_BASE_ADDR6  28'h4ffffff 
  // `define SYSMAP_FLG6        5'b10010

  // `define SYSMAP_BASE_ADDR7  28'hfffffff 
  // `define SYSMAP_FLG7        5'b01111

//End ct_mmu_sysmap


`ifdef FPGA 
`define SYSMAP_BASE_ADDR0  28'h01000
`define SYSMAP_FLG0        5'b01111

`define SYSMAP_BASE_ADDR1  28'h02000
`define SYSMAP_FLG1        5'b10000

`define SYSMAP_BASE_ADDR2  28'hd0000
`define SYSMAP_FLG2        5'b10000

`define SYSMAP_BASE_ADDR3  28'heffff
`define SYSMAP_FLG3        5'b01101

`define SYSMAP_BASE_ADDR4  28'hfffff
`define SYSMAP_FLG4        5'b01111

`define SYSMAP_BASE_ADDR5  28'h4000000
`define SYSMAP_FLG5        5'b01111

`define SYSMAP_BASE_ADDR6  28'h5000000 
`define SYSMAP_FLG6        5'b10000

`define SYSMAP_BASE_ADDR7  28'hfffffff 
`define SYSMAP_FLG7        5'b01111
`else
`define SYSMAP_BASE_ADDR0  28'h01000
`define SYSMAP_FLG0        5'b01111

`define SYSMAP_BASE_ADDR1  28'h02000
`define SYSMAP_FLG1        5'b10000

`define SYSMAP_BASE_ADDR2  28'hd0000
`define SYSMAP_FLG2        5'b10000

`define SYSMAP_BASE_ADDR3  28'heffff
`define SYSMAP_FLG3        5'b01101

`define SYSMAP_BASE_ADDR4  28'hfffff
`define SYSMAP_FLG4        5'b01111

`define SYSMAP_BASE_ADDR5  28'h4000000
`define SYSMAP_FLG5        5'b01111

`define SYSMAP_BASE_ADDR6  28'h5000000 
`define SYSMAP_FLG6        5'b10000

`define SYSMAP_BASE_ADDR7  28'hfffffff 
`define SYSMAP_FLG7        5'b01111
`endif


