// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "write_fast.c"

fn C.WRITE_FAST(port_name int, pin_number int, value u8)

// write_fast puts a logic 1 to a pin faster than the write function
@[as_macro]
pub fn write_fast(port_name int, pin_number int, value u8) {
	C.WRITE_FAST(port_name, pin_number, value)
}
