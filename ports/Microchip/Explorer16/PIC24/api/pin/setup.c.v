// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// setup macro configures a pin's input/output mode. This is expanded in this way:
//   pin.setup(a7, pin.in)
//     |
//	   +-->	a7_s = pin_in
//	          |
//	          +-->	a7_s = 1
//                    |
//                    +-->	TRISAbits.TRISA7 = 1
#define pin__setup(PIN_NAME, PIN_MODE)   PIN_NAME ## _s = PIN_MODE