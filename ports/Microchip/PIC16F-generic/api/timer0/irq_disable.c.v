// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: External interrupts management functions for 16F family
module timer0

// irq_disable disables the external interrupt
@[as_macro]
pub fn irq_disable() {
	C.T0IE = 0
}
