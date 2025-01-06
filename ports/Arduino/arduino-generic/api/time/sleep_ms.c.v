// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module time

// sleep is a delay function in milliseconds for Arduino devices 
@[inline]
pub fn sleep_ms(tms int) {
	C.delay(tms)
}