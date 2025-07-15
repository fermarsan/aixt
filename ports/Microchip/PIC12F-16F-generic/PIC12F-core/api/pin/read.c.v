// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// read function reads the logic value of a pin
@[as_macro]
pub fn read(name u8) u8 {
	return	u8( (C.GPIO  >>  name)  &  0x01 )
}
