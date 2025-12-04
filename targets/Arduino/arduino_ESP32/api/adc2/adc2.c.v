// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC functions
module adc2

fn C.analogread(id u8) u16
fn C.analogReadResolution(res any)	

// setup function sets the ADC resolution
@[inline]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}

//read function reads the value from the specified analog pin
@[inline]
pub fn read(id u8) u16 {
	return C.analogRead(id)
}