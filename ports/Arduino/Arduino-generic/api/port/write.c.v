// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions
module port

// write function writes an 8 bit value on a port
@[inline]
pub fn write(name u8, value u8) { 
	unsafe {
		*(&C.PORTB + (name*3)) = value
	}	
}