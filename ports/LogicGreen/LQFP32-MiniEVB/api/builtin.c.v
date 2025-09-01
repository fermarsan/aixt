// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (LQFP32 MiniEVB Nano - LGT8F328P port)
module main

// define analog pins
@[as_macro] pub const a0 =  A0  
@[as_macro] pub const a1 =  A1
@[as_macro] pub const a2 =  A2
@[as_macro] pub const a3 =  A3
@[as_macro] pub const a4 =  A4
@[as_macro] pub const a5 =  A5
@[as_macro] pub const a6 =  A6
@[as_macro] pub const a7 =  A7
@[as_macro] pub const a10 =  A10

enum __pin_names { // enumerated type for digital pin names
	d0
	d1
	d2
	d3
	d4
	d5
	d6
	d7
	d8
	d9
	d10
	d11
	d12
	d13
	d14
	d15
	d16
	d17
	d18
	d19
	d20
	d21
	d22
	d23
	d25 = 25
}

