// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module uart

// write function sends a single byte to the serial port
@[inline]
fn write(char u8) {  
	C.Serial.write(message)
}