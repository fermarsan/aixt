// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC functions
module adc

fn C.analogRead(name u8) u16

//read function reads the value from the specified analog pin
@[as_macro]
pub fn read(name u8) u16 {
	return C.analogRead(name)
}