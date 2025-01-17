// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2015
// License: MIT
//
// Description: ADC setup (XIAO-ESP32-xx port)
module adc

// setup function sets the ADC resolution
@[inline]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}