// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
//	- Fabián A. Rojas Acosta
//	- Alberto Pinzón Valero
//	- Fernando Martínez Santa
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
}

enum Pin_modes {
	pin__input = 0
	pin__output
	pin__in_pullup
}

enum Analog_pin_names {
	a0 = 14
	a1
	a2
	a3
	a4
	a5
	a6
	a7
}