// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module fast

#include "read.c"

fn C.READ_FAST(port_name int, pin_number int) u8

// read reads the logic value of a pin faster than the regular read function
@[as_macro]
pub fn read(port_name int, pin_number int) u8 {
	return C.READ_FAST(port_name, pin_number)
}
