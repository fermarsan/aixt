// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin-port functions (PIC12F8x port)
module port

// setup configures bit by bit the pin mode of a 8 bit port
@[as_macro]
pub fn setup(name u8, mode u8) {
	unsafe { 
		*(&C.TRISA + name) = mode 
	}	
}