// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin-port functions for 12F family
module port

@[as_macro] pub const all_inputs = 0b11111111   // port common modes
@[as_macro] pub const all_outputs = 0b00000000

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(mode u8) {
  C.TRISIO = mode
}

// write function writes an 8 bit value on a port
@[as_macro]
pub fn write(value u8) {
		C.GPIO = value
}

// read function reads an 8 bit value from a port
@[as_macro]
pub fn read() u8 {
		return u8(C.GPIO)
}

// b_pullups function enable or disable the pull up resistors of port B
// @[as_macro]
// pub fn b_pullups(enable bool) {
// 	C.RBPU = int(!enable)
// }
