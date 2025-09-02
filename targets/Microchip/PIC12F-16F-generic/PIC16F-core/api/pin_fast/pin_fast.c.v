// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin_fast

#include "pin_fast.c"

fn C.HIGH_FAST(port_name int, pin_number int)
fn C.LOW_FAST(port_name int, pin_number int)
fn C.READ_FAST(port_name int, pin_number int) u8
fn C.SETUP_FAST(port_name int, pin_number int, mode u8)
fn C.TOGGLE_FAST(port_name int, pin_number int)
fn C.WRITE_FAST(port_name int, pin_number int, value u8)

// high puts a logic 1 to a pin faster than the regular high function
@[as_macro]
pub fn high(port_name int, pin_number int) {
	C.HIGH_FAST(port_name, pin_number)
}

// low puts a logic 0 to a pin faster than the regular low function
@[as_macro]
pub fn low(port_name int, pin_number int) {
	C.LOW_FAST(port_name, pin_number)
}

// read reads the logic value of a pin faster than the regular read function
@[as_macro]
pub fn read(port_name int, pin_number int) u8 {
	return C.READ_FAST(port_name, pin_number)
}

// setup configures the mode of a pin faster than the regular setup function
@[as_macro]
pub fn setup(port_name int, pin_number int, mode u8) {
	C.SETUP_FAST(port_name, pin_number, mode)

}

// toggle toggles the logic value of a pin faster than the regular toggle function
@[as_macro]
pub fn toggle(port_name int, pin_number int) {
	C.TOGGLE_FAST(port_name, pin_number)
}

// write writes a logic value to a pin faster than the regular write function
@[as_macro]
pub fn write(port_name int, pin_number int, value u8) {
	C.WRITE_FAST(port_name, pin_number, value)
}
