// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: External interrupts management functions for 12F family
module ext

#include "ext.c"

@[as_macro] pub const rising  = 1
@[as_macro] pub const falling = 0

// setup set the falling or rising edge of the external interrupt
@[as_macro]
pub fn setup(edge any) {
	C.INTEDG = edge
}

// irq_enable enables the external interrupt
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.INTE = 1
}

// irq_disable disables the external interrupt
@[as_macro]
pub fn irq_disable() {
	C.INTE = 0
}