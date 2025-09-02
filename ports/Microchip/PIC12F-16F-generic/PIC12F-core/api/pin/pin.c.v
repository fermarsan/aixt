// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// pin names as macros
@[as_macro] pub const io0 = 0
@[as_macro] pub const io1 = 1
@[as_macro] pub const io2 = 2
@[as_macro] pub const io3 = 3
@[as_macro] pub const io4 = 4
@[as_macro] pub const io5 = 5


// IRQ (INT) pin
@[as_macro] pub const irq = 2

// pin modes as macros
@[as_macro] pub const output = 0
@[as_macro] pub const input  = 1

// high puts a logic 1 to a pin
@[as_macro]
pub fn high(name u8) {
    C.GPIO |=  0x01 << name
}

// low puts a logic 0 to a pin
@[as_macro]
pub fn low(name u8) {
	C.GPIO  &=  ~(0x01 << name)
}

// read function reads the logic value of a pin
@[as_macro]
pub fn read(name u8) u8 {
	return	u8( (C.GPIO  >>  name)  &  0x01 )
}

// setup configures the mode of a pin
@[as_macro]
pub fn setup(name u8, mode u8) {
	if mode == 1 { // as input (1)
		C.TRISIO |= (0x01 << name)
	} else { // as output (0)
		C.TRISIO &= ~(0x01 << name)
	}
}

// toggle function toggles the logic value of a pin
@[as_macro]
pub fn toggle(name u8) {
	C.GPIO  ^=  0x01 << name
}

// write function writes a logic value to a pin
@[as_macro]
pub fn write(name u8, value u8) {
	C.GPIO  &=  (~(0x01 << name))	// clean the bit first	
	C.GPIO  |=  (value << name)	
}