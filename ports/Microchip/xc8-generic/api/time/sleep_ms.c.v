// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: milliseconds delay function for XC8 compiler
module time

// sleep_ms function does a delay in milliseconds
@[as_macro]
pub fn sleep_ms(tms u16) {
	C.__delay_ms(tms)
}