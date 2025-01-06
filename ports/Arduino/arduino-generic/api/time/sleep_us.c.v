// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module time

// sleep is a delay function in microseconds for Arduino devices
@[inline]
pub fn sleep_us(tus int) {
	C.delayMicroseconds(tus)
}