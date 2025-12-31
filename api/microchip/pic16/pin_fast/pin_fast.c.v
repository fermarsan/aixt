// File: https://github.com/fermarsan/aixt/blob/main/api/Microchip/pic16_generic/pic16_core/api/pin_fast/pin_fast.c.v
// Author: Fernando M. Santa
// Date: 2025
//
// ## Description
// Pin management functions for the PIC16F family.
// This is the fast version that uses also the port name.
module pin_fast

#include "pin_fast.c"

fn C.HIGH_FAST(port_id u8, pin_id u8)
fn C.LOW_FAST(port_id u8, pin_id u8)
fn C.READ_FAST(port_id u8, pin_id u8) u8
fn C.SETUP_FAST(port_id u8, pin_id u8, mode u8)
fn C.TOGGLE_FAST(port_id u8, pin_id u8)
fn C.WRITE_FAST(port_id u8, pin_id u8, value u8)

// high function puts a logic `1` to a pin faster than the regular high function.
// `port_id` is the port id, for example `pin_fast.port_a` and
// `pin_id` is the pin id, for example `pin_fast.b3`.
@[as_macro]
pub fn high(port_id u8, pin_id u8) {
	C.HIGH_FAST(port_id, pin_id)
}

// low function puts a logic `0` to a pin faster than the regular low function.
// `port_id` is the port id, for example `pin_fast.port_a` and
// `pin_id` is the pin id, for example `pin_fast.b3`v.
@[as_macro]
pub fn low(port_id u8, pin_id u8) {
	C.LOW_FAST(port_id, pin_id)
}

// read reads the logic `value` of a pin faster than the regular read function.
// `port_id` is the port id, for example `pin_fast.port_a` and
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn read(port_id u8, pin_id u8) u8 {
	return C.READ_FAST(port_id, pin_id)
}

// setup configures the `mode` of a pin (by `id`) faster than the regular setup function.
// `port_id` is the port id, for example `pin_fast.port_a`,
// `pin_id` is the pin id, for example `pin_fast.b3`
// `mode` is the pin mode, `pin.input` or `pin.output`.
@[as_macro]
pub fn setup(port_id u8, pin_id u8, mode u8) {
	C.SETUP_FAST(port_id, pin_id, mode)

}

// toggle toggles the logic `value` of a pin faster than the regular toggle function.
// `port_id` is the port id, for example `pin_fast.port_a` and
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn toggle(port_id u8, pin_id u8) {
	C.TOGGLE_FAST(port_id, pin_id)
}

// write writes a logic `value` to a pin faster than the regular write function.
// `port_id` is the port id, for example `pin_fast.port_a` and
// `pin_id` is the pin id, for example `pin_fast.b3`
@[as_macro]
pub fn write(port_id u8, pin_id u8, value u8) {
	C.WRITE_FAST(port_id, pin_id, value)
}
