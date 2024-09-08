// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// write function prints data to the serial port as human-readable ASCII text
@[inline]
fn write(char u8) {  
	C.Serial.write(message)
}