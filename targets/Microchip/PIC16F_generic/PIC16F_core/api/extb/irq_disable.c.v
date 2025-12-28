// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
//
// ## Description
// External interrupts management functions for the PIC16F family.
module ext

// irq_disable disables the external interrupt
@[as_macro]
pub fn irq_disable() {
	C.RBIE = 0
}
