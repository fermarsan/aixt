// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Timer 0 management functions for 12F family
module timer0

// irq_enable enables the Timer0 overflow interrupt
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.T0IE = 1
}

