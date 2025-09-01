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

// fn C.pinMode(id u8, mode u8) // uncomment if not included in api/builtin.c.v
// fn C.digitalWrite(id u8, val u8) // uncomment if not included in api/builtin.c.v
fn C.digitalRead(id u8) u8
fn C.DIGITAL_TOGGLE(id u8)
// fn C.digitalPinToPort(id u8)
// fn C.digitalPinToBitMask(id u8)
// fn C.portInputRegister(id u32)


// new returns a new Pin instance
pub fn new(id u8, mode u8) &Pin {
    mut p := Pin {
        id:    id
    }
    p.setup(mode)
    return p
}