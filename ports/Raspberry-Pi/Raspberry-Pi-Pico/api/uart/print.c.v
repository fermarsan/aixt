// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// print function prints data to the serial port as human-readable ASCII text
@[inline]
pub fn print(message string) {  
	C.SERIAL1_PRINT(message)
}