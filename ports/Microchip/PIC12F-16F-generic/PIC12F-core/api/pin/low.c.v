// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// low puts a logic 0 to a pin
@[as_macro]
pub fn low(name u8) {
	C.GPIO  &=  ~(0x01 << name)
}
