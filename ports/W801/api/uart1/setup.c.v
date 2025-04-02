// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart1

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.SERIAL1_BEGIN(baud_rate)
}