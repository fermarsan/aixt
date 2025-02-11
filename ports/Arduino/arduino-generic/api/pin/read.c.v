// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// read function reads the value from a specified digital pin, either HIGH or LOW
@[inline]
pub fn read(name u8) u8 {
	return C.digitalRead(name)
}