// File: https://github.com/fermarsan/aixt/blob/main/api/Microchip/pic16_generic/pic16_core/api/ext/ext.c.v
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// External interrupts management functions for the PIC16F family.
module ext

// flag to enables the interrupt service code
@[as_macro] const irq_in_use = true

@[as_macro] pub const rising  = 1 // edge of the external interrut
@[as_macro] pub const falling = 0

// setup function set the falling or rising `edge` of the external interrupt.
// `edge` can be `ext.falling` or `ext.rising`.
@[as_macro]
pub fn setup(edge any) {
	C.INTEDG = edge
}

// irq_enable function enables the external interrupt
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.INTE = 1
}

// irq_disable function disables the external interrupt
@[as_macro]
pub fn irq_disable() {
	C.INTE = 0
}
