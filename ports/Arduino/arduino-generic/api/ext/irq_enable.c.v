// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: External interrupts management functions for 16F family
module ext

// irq_enable enables the external interrupt
@[as_macro]
pub fn irq_enable(pin any, mode any) {
	// C.attachInterrupt(C.digitalPinToInterrupt(pin), C.ext_isr(pin), mode)
	C.attachInterrupt(C.digitalPinToInterrupt(pin), C.ptr_ext_isr(pin), mode)
}

