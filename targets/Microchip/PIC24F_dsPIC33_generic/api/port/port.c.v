// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin port management functions (Exp16-PIC24 port)
module port


// port common modes
@[as_macro] pub const all_inputs = 0b1111111111111111
@[as_macro] pub const all_outputs = 0b0000000000000000

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(id u8, mode u16) {
	unsafe {
		*(&C.TRISA + (id * 3)) = mode
	}
}

// write function writes an 8 bit value on a port
@[as_macro]
pub fn write(id u8, value u16) {
	unsafe {
		*(&C.LATA + (id * 3)) = value
	}
}

// read function reads an 8 bit value from a ports
@[as_macro]
pub fn read(id u8) u16 {
	unsafe {
		return u8(*(&C.PORTA + (id * 3)))
	}
}

// b_pullups function enable or disable the pull up resistors of port B
// @[as_macro]
// pub fn b_pullups(enable bool) {
// 	C.RBPU = int(!enable)
// }
