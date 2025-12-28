// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// External interrupts management functions for 12F family
module ext

@[as_macro] const irq_in_use = true

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
