// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in milliseconds for the Aixt PC port. 
@[inline]
pub fn sleep_ms(tms int) {
	C.sleep_ms(tms)
}