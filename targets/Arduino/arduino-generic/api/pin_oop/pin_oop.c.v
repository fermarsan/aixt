// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions for Arduino devices (OOP)
module pin_oop

// Pin is a struct that represents a digital pin
pub struct Pin {
    id  u8
}

fn C.pinMode(id u8, mode u8) // uncomment if not included in api/builtin.c.v
fn C.digitalWrite(id u8, val u8) // uncomment if not included in api/builtin.c.v
fn C.digitalRead(id u8) u8
fn C.DIGITAL_TOGGLE(id u8)
// fn C.digitalPinToPort(id u8)
// fn C.digitalPinToBitMask(id u8)
// fn C.portInputRegister(id u32)


// new returns a new Pin instance
pub fn new(id u8, mode u8) &Pin {
    mut p := &Pin {
        id: id
    }
    p.setup(mode)
    return p
}

// setup configures a pin's input/output mode
// @[as_macro]
@[inline]
pub fn (p Pin) setup(mode u8) {   
    C.pinMode(p.id, mode)
}

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) write(val u8) {  
    C.digitalWrite(p.id, val)
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

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn (p Pin) read() u8 {
	return C.digitalRead(p.id)
}
