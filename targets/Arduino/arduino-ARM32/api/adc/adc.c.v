// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC functions
module adc

fn C.analogReadResolution(res any)	

// setup function sets the ADC resolution
@[as_macro]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}