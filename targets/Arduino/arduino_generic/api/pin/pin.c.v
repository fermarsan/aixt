// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions Arduino devices
module pin

fn C.pinMode(id u8, mode u8)	 
fn C.digitalWrite(id u8, val u8) 
fn C.digitalRead(id u8) u8
fn C.DIGITAL_TOGGLE(id u8)
// fn C.digitalPinToPort(name u8)
// fn C.digitalPinToBitMask(name u8)
// fn C.portInputRegister(name u32)


// pin modes
@[as_macro] pub const input		  = u8(C.INPUT)
@[as_macro] pub const output	  = u8(C.OUTPUT)
@[as_macro] pub const in_pullup   = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

// setup configures a pin's input/output mode
@[as_macro]
pub fn setup(id u8, mode u8) {   
    C.pinMode(id, mode)
}

// high puts a high value (logic 1) to a specific pin
@[as_macro]
pub fn high(id u8) {   
    C.digitalWrite(id, C.HIGH)
}

// low puts a low value (logic 0) to a specific pin
@[as_macro]
pub fn low(id u8) {   
    C.digitalWrite(id, C.LOW)
}

// read function reads the value from a specified digital pin, either HIGH or LOW
@[as_macro]
pub fn read(id u8) u8 {
	return C.digitalRead(id)
}

// write puts a logic value to a specific pin
@[as_macro]
pub fn write(id u8, val u8) {  
    C.digitalWrite(id, val)
}