// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: External interrupts management functions for Arduino Nano
module ext

// setup set the mode/edge of the external interrupt
@[as_macro]
pub fn setup(mode any) {
	ext_int_mode = mode
}

