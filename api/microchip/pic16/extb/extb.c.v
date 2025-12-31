// File: https://github.com/fermarsan/aixt/blob/main/api/Microchip/pic16_generic/pic16_core/api/extb/extb.c.v
// Author: Fernando M. Santa
// Date: 2025
//
// ## Description
// External interrupts management functions for the PIC16F family.
module extb

#include "extb.c"

// irq_disable disables the external interrupt by changes of RB7-RB4 pins.
@[as_macro]
pub fn irq_disable() {
	C.RBIE = 0
}

// irq_enable enables the external interrupt by changes of RB7-RB4 pins.
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.RBIE = 1
}
