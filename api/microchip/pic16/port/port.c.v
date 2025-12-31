// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// Pin-port functions for the PIC16F family.
module port

// setup function configures bit by bit the pin mode of a 8-bit port.
// `id` is the port id, for example `port.c`,
// `mode` is a byte that defines which pin is input (`1`) or output (`0`),
// for example `0b00001111` configures the 4 MSBs as outputs and the
// rest as inputs.
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe {
		*(&C.TRISA + id) = mode
	}
}

// write function writes an 8-bit `value` on a port.
// `id` is the port id, for example `port.c`.
@[as_macro]
pub fn write(id u8, value u8) {
	unsafe {
		*(&C.PORTA + id) = value
	}
}

// read function reads an 8-bit `value` from a port.
// `id` is the port id, for example `port.c`.
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return u8(*(&C.PORTA + id))
	}
}

// b_pullups function enable or disable the pull up resistors of PORTB
// `enable` must be `false` or `true`
@[as_macro]
pub fn b_pullups(enable bool) {
	C.RBPU = int(!enable)
}
