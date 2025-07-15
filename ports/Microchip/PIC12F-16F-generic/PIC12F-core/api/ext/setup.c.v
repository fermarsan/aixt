// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025-2025
// License: MIT
//
// Description: External interrupts management functions for 12F family
module ext

// setup set the falling or rising edge of the external interrupt
@[as_macro]
pub fn setup(edge any) {
	C.INTEDG = edge
}

