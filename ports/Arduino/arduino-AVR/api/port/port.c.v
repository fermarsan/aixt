// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions
module port

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(name u8, mode u8) {
	unsafe { 
		*(&C.DDRB + (name*3)) = ~mode 
	}	
}

// write function writes an 8 bit value on a port
@[as_macro]
pub fn write(name u8, value u8) { 
	unsafe {
		*(&C.PORTB + (name*3)) = value
	}	
}

// read function reads an 8 bit value from a port
@[as_macro]
pub fn read(name u8) u8 {
	unsafe {
		return u8(*(&C.PINB + (name*3)))
	}	
}


