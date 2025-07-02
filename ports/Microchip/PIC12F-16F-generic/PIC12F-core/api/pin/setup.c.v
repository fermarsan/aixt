// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// setup configures the mode of a pin
@[as_macro]
pub fn setup(name u8, mode u8) {
	if mode == 1 { // as input (1)
		C.TRISIO |= (0x01 << name)
	} else { // as output (0)
		C.TRISIO &= ~(0x01 << name)
	}
}
