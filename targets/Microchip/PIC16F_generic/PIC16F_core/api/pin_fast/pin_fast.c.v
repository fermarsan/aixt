// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// Pin management functions for the PIC16F family,
// this is the fast version that uses also the port name
module pin_fast

#include "pin_fast.c"

fn C.HIGH_FAST(port_id int, pin_id int)
fn C.LOW_FAST(port_id int, pin_id int)
fn C.READ_FAST(port_id int, pin_id int) u8
fn C.SETUP_FAST(port_id int, pin_id int, mode u8)
fn C.TOGGLE_FAST(port_id int, pin_id int)
fn C.WRITE_FAST(port_id int, pin_id int, value u8)

// high function puts a logic `1` to a pin faster than the regular high function. <br>
// `port_id` is the port id, for example `pin_fast.port_b`. <br>
// `pin_id` is the pin id, for example `pin_fast.b3`. <br>
@[as_macro]
pub fn high(port_id int, pin_id int) {
	C.HIGH_FAST(port_id, pin_id)
}

// low function puts a logic `0` to a pin faster than the regular low function. \
// `port_id` is the port id, for example `pin_fast.port_b`. \
// `pin_id` is the pin id, for example `pin_fast.b3`v. \
@[as_macro]
pub fn low(port_id int, pin_id int) {
	C.LOW_FAST(port_id, pin_id)
}

// read reads the logic `value` of a pin faster than the regular read function
// `port_id` is the port id, for example `pin_fast.port_b`
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn read(port_id int, pin_id int) u8 {
	return C.READ_FAST(port_id, pin_id)
}

// setup configures the mode of a pin faster than the regular setup function
// `port_id` is the port id, for example `pin_fast.port_b`
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn setup(port_id int, pin_id int, mode u8) {
	C.SETUP_FAST(port_id, pin_id, mode)

}

// toggle toggles the logic `value` of a pin faster than the regular toggle function
// `port_id` is the port id, for example `pin_fast.port_b`
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn toggle(port_id int, pin_id int) {
	C.TOGGLE_FAST(port_id, pin_id)
}

// write writes a logic `value` to a pin faster than the regular write function
// `port_id` is the port id, for example `pin_fast.port_b`
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn write(port_id int, pin_id int, value u8) {
	C.WRITE_FAST(port_id, pin_id, value)
}
