// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module uart2

// write function sends a single byte to the serial port
@[inline]
pub fn write(character u8) {  
	C.SERIAL2_WRITE(character)
}