// Author: Fernando M. Santa
// Date: 2026
//
// ## Description
// Pin management in ESP-IDF (OOP)
module pin


// pin modes
@[as_macro] pub const input		  = u8(C.GPIO_MODE_INPUT)
@[as_macro] pub const output	  = u8(C.GPIO_MODE_OUTPUT)
@[as_macro] pub const in_out	  = u8(C.GPIO_MODE_INPUT_OUTPUT)

fn C.gpio_set_direction(id u8, mode u8)
fn C.gpio_set_level(id u8, val u8)
fn C.gpio_get_level(id u8) u8
fn C.gpio_reset_pin(id u8)

// Pin is a struct that represents a digital pin
pub struct Pin {
pub mut:
    id      u8
}

// new returns a new Pin instance
pub fn Pin.new(id u8) Pin {
    return Pin {
        id:     id
    }
}

// setup configures a pin's input/output mode
// @[as_macro]
@[inline]
pub fn (mut p Pin) setup(mode u8) {   
    C.gpio_reset_pin(p.id)
    C.gpio_set_direction(p.id, mode)
}

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) write(val u8) {  
    C.gpio_set_level(p.id, val)
}


// high puts a high value (logic 1) to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) high() {   
    C.gpio_set_level(p.id, 1)
}

// low puts a low value (logic 0) to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) low() {   
    C.gpio_set_level(p.id, 0)
}

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn (mut p Pin) read() u8 {
	return C.gpio_get_level(p.id)
}
