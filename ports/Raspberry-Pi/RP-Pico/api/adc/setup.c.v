// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC setup (Raspberry Pi Pico port)
module adc

// setup function sets the ADC resolution
@[inline]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}