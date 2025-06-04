// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 16F family
module fast

#include "write.c"

fn C.WRITE_FAST(port_name int, pin_number int, value u8)

// write writes a logic value to a pin faster than the regular write function
@[as_macro]
pub fn write(port_name int, pin_number int, value u8) {
	C.WRITE_FAST(port_name, pin_number, value)
}
