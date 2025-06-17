// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// Description: Builtin definitions (Nucleo-L031K6 port) 
module main

fn C.pinMode(name u8, mode u8)		// uncomment if not included in api/builtin.c.v 
fn C.digitalWrite(name u8, val u8)	// uncomment if not included in api/builtin.c.v 	

// builtin LED
@[as_macro] const led_0 = 33
@[as_macro] const sw_0 = 36
