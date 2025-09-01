// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: External interrupts management functions for 16F family
module ext


#include "ext.c"

// fn C.ext_isr(pin any) fn()
fn C.ptr_ext_isr(pin any) fn()
fn C.attachInterrupt(pin any, handler fn(), mode any)
fn C.detachInterrupt(pin any)	
fn C.digitalPinToInterrupt(pin any)

@[as_macro] pub const rising  = C.RISING
@[as_macro] pub const falling = C.FALLING
@[as_macro] pub const change  = C.CHANGE

// irq_enable enables the external interrupt
@[as_macro]
pub fn irq_enable(pin any, mode any) {
	// C.attachInterrupt(C.digitalPinToInterrupt(pin), C.ext_isr(pin), mode)
	C.attachInterrupt(C.digitalPinToInterrupt(pin), C.ptr_ext_isr(pin), mode)
}

// irq_disable disables the external interrupt
@[as_macro]
pub fn irq_disable(pin any) {
	C.detachInterrupt(C.digitalPinToInterrupt(pin))
}
