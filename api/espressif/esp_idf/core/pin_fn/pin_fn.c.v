// Author: Fernando M. Santa
// Date: 2026
//
// ## Description
// Pin management in ESP-IDF
module pin


// pin modes
@[as_macro] pub const input		  = u8(C.GPIO_MODE_INPUT)
@[as_macro] pub const output	  = u8(C.GPIO_MODE_OUTPUT)
@[as_macro] pub const in_out	  = u8(C.GPIO_MODE_INPUT_OUTPUT)

fn C.gpio_set_direction(id u8, mode u8)
fn C.gpio_set_level(id u8, val u8)
fn C.gpio_get_level(id u8) u8
fn C.gpio_reset_pin(id u8)


// setup configures a pin's input/output mode
// @[as_macro]
@[inline]
pub fn setup(id u8, mode u8) {   
    C.gpio_reset_pin(id)
    C.gpio_set_direction(id, mode)
}

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn write(id u8, val u8) {  
    C.gpio_set_level(id, val)
}


// high puts a high value (logic 1) to a specific pin
// @[as_macro]
@[inline]
pub fn high(id u8) {   
    C.gpio_set_level(id, 1)
}

// low puts a low value (logic 0) to a specific pin
// @[as_macro]
@[inline]
pub fn low(id u8) {   
    C.gpio_set_level(id, 0)
}

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn read(id u8) u8 {
	return C.gpio_get_level(id)
}
