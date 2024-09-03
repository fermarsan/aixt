// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F84A port)
module port

// write function writes an 8 bit value on a port
@[inline]
pub fn write(name u8, value u8) {
	addr = &(C.PORTA) + name
	unsafe { *addr = value }	
}