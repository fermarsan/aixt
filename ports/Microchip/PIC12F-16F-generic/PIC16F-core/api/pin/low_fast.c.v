// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "low_fast.c"

fn C.LOW_FAST(port_name int, pin_number int)

// low_fast puts a logic 1 to a pin faster than the low function
@[as_macro]
pub fn low_fast(port_name int, pin_number int) {
	C.LOW_FAST(port_name, pin_number)
}
