// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// Reads incoming serial data
@[inline]
fn read() u8 {
	return C.Serial.read()
}