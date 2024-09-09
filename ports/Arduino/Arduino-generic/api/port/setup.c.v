// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (ATmega328p)
module port

// setup configures bit by bit the pin mode of a 8 bit port
@[inline]
pub fn setup(name u8, mode u8) {
	unsafe { 
		*(&C.DDRB + (name*3)) = ~mode 
	}	
}