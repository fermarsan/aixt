// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// Description: Builtin definitions (Blue-Pill port) 
module main

// builtin LED
@[as_macro]	pub const led0 = 17

fn C.pinMode(name u8, mode u8)
fn C.digitalWrite(name u8, val u8)

fn init() {
	C.pinMode(led0, u8(C.OUTPUT))		// setup the pin of led0 as output
	C.digitalWrite(led0, u8(C.HIGH))	// an turn it off
}
