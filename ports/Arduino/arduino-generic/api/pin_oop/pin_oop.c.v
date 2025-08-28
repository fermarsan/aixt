// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions for Arduino devices (OOP)
module pin_oop

// Pin is a struct that represents a digital pin
pub struct Pin {
    id u8
}

// new returns a new Pin instance
// pub fn new(pin_id u8) Pin {
//     return Pin{
//         id: pin_id
//     }
// }

// setup configures a pin's input/output mode
// @[as_macro]
@[inline]
pub fn (p Pin) setup(mode u8) {   
    C.pinMode(p.id, mode)
}

// high puts a high value (logic 1) to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) high() {   
    C.digitalWrite(p.id, C.HIGH)
}

// low puts a low value (logic 0) to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) low() {   
    C.digitalWrite(p.id, C.LOW)
}

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) write(val u8) {  
    C.digitalWrite(p.id, val)
}

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn (p Pin) read() u8 {
	return C.digitalRead(p.id)
}

// fn C.pinMode(pin_id u8, mode u8) // uncomment if not included in api/builtin.c.v
// fn C.digitalWrite(pin_id u8, val u8) // uncomment if not included in api/builtin.c.v
fn C.digitalRead(pin_id u8) u8
fn C.DIGITAL_TOGGLE(pin_id u8)
// fn C.digitalPinToPort(pin_id u8)
// fn C.digitalPinToBitMask(pin_id u8)
// fn C.portInputRegister(pin_id u32)