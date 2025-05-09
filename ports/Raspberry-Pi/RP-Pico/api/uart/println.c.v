// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: ernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// print function prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[inline]
pub fn println(message string) {  
	C.SERIAL1_PRINTLN(message)
}