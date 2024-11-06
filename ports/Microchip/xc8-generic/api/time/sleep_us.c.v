// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: microseconds delay function for XC8 compiler
module time

// sleep_us function does a delay in microseconds
@[inline]
pub fn sleep_us(tus u16) {
	C.__delay_us(tus)
}