// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
//
// ## Description
// Pin management functions for Arduino devices (OOP)
module pin


// pin modes
@[as_macro] pub const input		  = u8(C.INPUT)
@[as_macro] pub const output	  = u8(C.OUTPUT)
@[as_macro] pub const in_pullup   = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

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
    C.pinMode(p.id, mode)
}

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) write(val u8) {  
    C.digitalWrite(p.id, val)
}


// high puts a high value (logic 1) to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) high() {   
    C.digitalWrite(p.id, C.HIGH)
}

// low puts a low value (logic 0) to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) low() {   
    C.digitalWrite(p.id, C.LOW)
}

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn (mut p Pin) read() u8 {
	return C.digitalRead(p.id)
}
