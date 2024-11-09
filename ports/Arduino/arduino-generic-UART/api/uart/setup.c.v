// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[as_macro]
pub fn setup(baud_rate int) {
	C.Serial.begin(baud_rate)
}