// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions for 16F family
module port

// // port names
// @[as_macro] pub const a = 0
// @[as_macro] pub const b = 1
// @[as_macro] pub const c = 2
// @[as_macro] pub const d = 3
// @[as_macro] pub const e = 4

// // port common modes
// @[as_macro] pub const all_inputs = 0b11111111
// @[as_macro] pub const all_outputs = 0b00000000

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe {
		*(&C.TRISA + id) = mode
	}
}

// write function writes an 8 bit value on a port
@[as_macro]
pub fn write(id u8, value u8) {
	unsafe {
		*(&C.PORTA + id) = value
	}
}

// read function reads an 8 bit value from a port
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return u8(*(&C.PORTA + id))
	}
}

// b_pullups function enable or disable the pull up resistors of port B
@[as_macro]
pub fn b_pullups(enable bool) {
	C.RBPU = int(!enable)
}
