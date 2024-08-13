// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (Arduino Nano - ATmega328P port)
module pin

pub const ( // enumerated type for digital pin names
	d0  = 0
	d1  = 1
	d2  = 2
	d3  = 3
	d4  = 4
	d5  = 5
	d6  = 6
	d7  = 7
	d8  = 8
	d9  = 9
	d10 = 10
	d11 = 11
	d12 = 12
	d13 = 13
	d14 = 14
	d15 = 15
	d16 = 16
	d17 = 17
	d18 = 18
	d19 = 19
)

pub const (
	input = 0x0
	output = 0x1
	in_pullup = 0x2
)