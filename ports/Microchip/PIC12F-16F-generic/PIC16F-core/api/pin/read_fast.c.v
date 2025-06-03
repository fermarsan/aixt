// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "read_fast.c"

fn C.READ_FAST(port_name int, pin_number int) u8

// read_fast puts a logic 1 to a pin faster than the read function
@[as_macro]
pub fn read_fast(port_name int, pin_number int) u8 {
	return C.READ_FAST(port_name, pin_number)
}
