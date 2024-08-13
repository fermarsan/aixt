// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// Sets the data rate in bits per second (baud) for serial data transmission
@[inline]
fn setup(baud_rate int) {
	C.Serial.begin(baud_rate)
}