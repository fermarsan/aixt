// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "setup_fast.c"

fn C.SETUP_FAST(port_name int, pin_number int, mode u8)

// setup configures the mode of a pin
@[as_macro]
pub fn setup_fast(port_name int, pin_number int, mode u8) {
	C.SETUP_FAST(port_name, pin_number, mode)

}
