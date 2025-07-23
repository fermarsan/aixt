// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// toggle function toggles the logic value of a pin
@[as_macro]
pub fn toggle(name u8) {
	C.GPIO  ^=  0x01 << name
}
