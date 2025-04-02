// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// Sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(BAUD_RATE) {
	C.Serial.begin(BAUD_RATE)
}