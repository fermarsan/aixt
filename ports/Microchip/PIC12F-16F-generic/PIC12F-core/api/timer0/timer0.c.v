// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Timer0 functions for 12F family
module timer0

#include "timer0.c"

__global (
	timer0__initial = u8(0)
)

// @[as_macro] const no_pre  = u8(255)
// @[as_macro] const pre_2   = u8(0b000)
// @[as_macro] const pre_4   = u8(0b001)
// @[as_macro] const pre_8   = u8(0b010)
// @[as_macro] const pre_16  = u8(0b011)
// @[as_macro] const pre_32  = u8(0b100)
// @[as_macro] const pre_64  = u8(0b101)
// @[as_macro] const pre_128 = u8(0b110)
// @[as_macro] const pre_256 = u8(0b111)