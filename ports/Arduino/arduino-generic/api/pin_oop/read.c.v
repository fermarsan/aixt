// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
module pin_oop

// read function reads the value from a specified digital pin, either HIGH or LOW
// @[as_macro]
@[inline]
pub fn (p Pin) read() u8 {
	return C.digitalRead(p.id)
}
