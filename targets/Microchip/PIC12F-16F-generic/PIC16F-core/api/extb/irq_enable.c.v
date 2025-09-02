// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: External interrupts management functions for 16F family
module ext

// irq_enable enables the external interrupt
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.RBIE = 1
}
