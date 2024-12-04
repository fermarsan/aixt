// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: External interrupts management functions for 16F family
module ext

// edge set the falling or rising edge of the external interrupt
@[as_macro]
fn edge(_edge any) {
	C.INTEDG = _edge
}

