// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions for 16F family
module port

// read function reads an 8 bit value from a port
@[as_macro]
pub fn read(name u8) u8 {
	unsafe {
		return u8(*(&C.PORTA + name))
	}
}
