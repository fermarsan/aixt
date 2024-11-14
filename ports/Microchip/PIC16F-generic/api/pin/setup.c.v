// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

#include "setup.c"

fn C.PIN_SETUP(name u8, mode u8)

// setup configures the mode of a pin
// @[as_macro]
pub fn setup(name u8, mode u8) {
	C.PIN_SETUP(name, mode)
}
