// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// Prints data to the serial port as human-readable ASCII text
@[inline]
pub fn uart.print(MESSAGE) {
	C.Serial.print(MESSAGE)
}