// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "toggle_fast.c"

fn C.TOGGLE_FAST(port_name int, pin_number int)

// toggle_fast puts a logic 1 to a pin faster than the toggle function
@[as_macro]
pub fn toggle_fast(port_name int, pin_number int) {
	C.TOGGLE_FAST(port_name, pin_number)
}
