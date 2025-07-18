// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// write function writes a logic value to a pin
@[as_macro]
pub fn write(name u8, value u8) {
	C.GPIO  &=  (~(0x01 << name))	// clean the bit first	
	C.GPIO  |=  (value << name)	
}
