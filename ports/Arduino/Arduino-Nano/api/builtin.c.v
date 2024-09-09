// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
//	- Fabián A. Rojas Acosta
//	- Alberto Pinzón Valero
//	- Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (Arduino Nano - ATmega328P port)
module main

enum Pin_names { // enumerated type for digital pin names
	pin__d0 = 0 
	pin__d1 
	pin__d2 
	pin__d3 
	pin__d4 
	pin__d5 
	pin__d6 
	pin__d7 
	pin__d8 
	pin__d9 
	pin__d10 
	pin__d11 
	pin__d12 
	pin__d13 
	pin__d14 
	pin__d15 
	pin__d16 
	pin__d17 
	pin__d18 
	pin__d19 
	pin__d20 
	pin__d21 
}

enum Pin_modes {
	pin__input = 0
	pin__output
	pin__in_pullup
}

enum ADC_pin_names {
	adc__a0 = 14
	adc__a1
	adc__a2
	adc__a3
	adc__a4
	adc__a5
	adc__a6
	adc__a7
}

enum Port__names {
	port__b = 0
	port__c
	port__d
}

enum Builtin_names {
	led0 = 13
}
