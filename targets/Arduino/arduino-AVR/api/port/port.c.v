// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions
module port

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe { 
		*(&C.DDRB + (id*3)) = ~mode 
	}	
}

// write function writes an 8 bit value on a port
@[as_macro]
pub fn write(id u8, value u8) { 
	unsafe {
		*(&C.PORTB + (id*3)) = value
	}	
}

// read function reads an 8 bit value from a port
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return u8(*(&C.PINB + (id*3)))
	}	
}


