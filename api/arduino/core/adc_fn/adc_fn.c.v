// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// ADC functions
module adc_fn

fn C.analogRead(id u8) u16

// read function reads the value from the specified analog pin
@[as_macro]
pub fn read(id u8) u16 {
	return C.analogRead(id)
}
