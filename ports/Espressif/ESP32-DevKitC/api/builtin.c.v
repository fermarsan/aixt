// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (ESP32-DevKitC port)
module main

enum Pin_names { // enumerated type for digital pin names
	gpio0= 0 
	gpio1
	gpio2
	gpio3
	gpio4
	gpio5
	gpio6
	gpio7
	gpio8
	gpio9
	gpio10
	gpio11
	gpio12
	gpio13
	gpio14
	gpio15
	gpio16
	gpio17
	gpio18
	gpio19
	gpio20
	gpio21
	gpio22
	gpio23
	gpio24
	gpio25
	gpio26
	gpio27
	gpio28
	gpio29
	gpio30
	gpio31
	gpio32
	gpio33
	gpio34
	gpio35
	gpio36
}

enum Pin_modes {
	input = C.INPUT
	output
	in_pullup
}

enum ADC_pin_names {
	adc2_1 = 0
	adc2_2 = 2
	adc2_0 = 4
	adc2_5 = 12
	adc2_4
	adc2_6
	adc2_3
	adc2_8 = 25
	adc2_9
	adc2_7
	adc1_4 = 32
	adc1_5
	adc1_6
	adc1_7
	adc1_0
	adc1_1 = 39
}
