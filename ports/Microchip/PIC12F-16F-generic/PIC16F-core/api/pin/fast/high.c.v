// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module fast

#include "high.c"

fn C.HIGH_FAST(port_name int, pin_number int)

// high puts a logic 1 to a pin faster than the regular high function
@[as_macro]
pub fn high(port_name int, pin_number int) {
	C.HIGH_FAST(port_name, pin_number)
}
