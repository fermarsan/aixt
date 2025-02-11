// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// // Description: ADC setup (Blue Pill port) 
module adc

// setup function sets the ADC resolution
@[inline]
pub fn setup(res u8) {
	C.analogReadResolution(res)
}
