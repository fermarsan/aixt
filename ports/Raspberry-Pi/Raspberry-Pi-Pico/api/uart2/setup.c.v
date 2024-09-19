// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart2

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.Serial2.begin(baud_rate)
}