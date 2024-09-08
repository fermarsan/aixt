// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// Prints data to the serial port as human-readable ASCII text
@[inline]
fn print(message string) {  
	C.Serial.print(message)
}