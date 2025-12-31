// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// ADC functions
module adc

fn C.analogReadResolution(res any)

// setup function sets the ADC resolution
@[as_macro]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}
