// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module fast

#include "toggle.c"

fn C.TOGGLE_FAST(port_name int, pin_number int)

// toggle toggles the logic value of a pin faster than the regular toggle function
@[as_macro]
pub fn toggle(port_name int, pin_number int) {
	C.TOGGLE_FAST(port_name, pin_number)
}
