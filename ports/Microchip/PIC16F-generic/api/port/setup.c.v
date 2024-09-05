// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F84A port)
module port

// setup configures bit by bit the pin mode of a 8 bit port
@[inline]
pub fn setup(name u8, mode u8) {
	unsafe { 
		*(&C.TRISA + name) = mode 
	}	
}