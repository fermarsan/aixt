// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC setup
module adc

// setup function sets the ADC resolution
@[as_macro]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}