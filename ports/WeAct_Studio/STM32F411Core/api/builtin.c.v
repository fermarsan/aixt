// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// Description: Builtin definitions (STM32F411Core port) 
module main


@[as_macro] const led0 = 31	// builtin LED
@[as_macro] const sw0 = 0		// builtin Switch

fn C.pinMode(name u8, mode u8)		// uncomment if not included in api/builtin.c.v 
fn C.digitalWrite(name u8, val u8)	// uncomment if not included in api/builtin.c.v 	

fn init() {
	C.pinMode(sw0, u8(C.INPUT_PULLDOWN))	
	C.pinMode(led0, u8(C.OUTPUT))		// setup the pin of led0 as output
	C.digitalWrite(led0, u8(C.LOW))	// an turn it off
}