// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "high_fast.c"

fn C.HIGH_FAST(port_name u8, pin_number u8)

// high_fast puts a logic 1 to a pin faster than the high function
@[as_macro]
pub fn high_fast(port_name u8, pin_number u8) {
	C.HIGH_FAST(port_name, pin_number)
}
