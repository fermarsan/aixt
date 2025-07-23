// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Timer0 functions for 12F family
module timer0

// restart the Timer0 with the predefined starting value
@[as_macro]
pub fn restart() {
	C.TMR0 = u8(timer0__initial)
}