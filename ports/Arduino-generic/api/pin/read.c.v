// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// read function reads the value from a specified digital pin, either HIGH or LOW
@[inline]
pub fn read(name int) int {
	return C.digitalRead(name)
}