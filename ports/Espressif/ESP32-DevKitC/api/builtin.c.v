// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (ESP32-DevKitC port)
module main

enum Pin_names { // enumerated type for digital pin names
	io0 = 0 
	io1 
	io2 
	io3 
	io4 
	io5 
	io6 
	io7 
	io8 
	io9 
	io10 
	io11 
	io12 
	io13 
	io14 
	io15 
	io16 
	io17 
	io18 
	io19 
	io20 
	io21
	io22
	io23
	io24
	io25
	io26
	io27
	io28
	io29
	io30
	io31
	io32
	io33
	io34
	io35
	io36
}

enum Pin_modes {
	input = C.INPUT
	output
	in_pullup
}

// enum ADC_pin_names {
// 	adc_00 = 14
// 	adc_00
// 	adc_00
// 	adc_00
// 	adc_00
// 	adc_00
// 	adc_00
// 	adc_00
// }
