// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module adc

//read function reads the value from the specified analog pin
@[as_macro]
pub fn read(name u8) u16 {
	return C.analogRead(name)
}