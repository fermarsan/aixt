// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module fast

#include "low.c"

fn C.LOW_FAST(port_name int, pin_number int)

// low puts a logic 0 to a pin faster than the regular low function
@[as_macro]
pub fn low(port_name int, pin_number int) {
	C.LOW_FAST(port_name, pin_number)
}
