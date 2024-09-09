// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: milliseconds delay function (PIC16F84A port)
module time

// sleep_ms function does a delay in milliseconds
@[inline]
pub fn sleep_ms(tms u16) {
	C.__delay_ms(tms)
}