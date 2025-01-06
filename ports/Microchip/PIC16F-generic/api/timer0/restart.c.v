// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Timer0 functions for 16F family
module timer0

// restart configures the Timer0
@[as_macro]
pub fn restart() {
	C.TMR0 = u8(timer0__initial)
}