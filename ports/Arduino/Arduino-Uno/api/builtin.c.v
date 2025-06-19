// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Builtin definitions (Arduino Uno - ATmega328P port)
module main

#include "builtin.c"

@[as_macro]	const led0 = 13


fn C.pinMode(name u8, mode u8)
fn C.digitalWrite(name u8, val u8)

fn init() {
	C.pinMode(led0, u8(C.OUTPUT))		// setup the pin of led0 as output
	C.digitalWrite(led0, u8(C.LOW))	// an turn it off
}
