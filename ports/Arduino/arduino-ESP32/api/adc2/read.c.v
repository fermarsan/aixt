// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module adc2

//read function reads the value from the specified analog pin
@[inline]
pub fn read(name u8) u16 {
	return C.analogRead(name)
}