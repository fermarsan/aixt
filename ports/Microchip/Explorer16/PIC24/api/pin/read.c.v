// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// read macro reads the value of an input pin. This is expanded in this way:
//   x = pin.read(a7)
//     |
//	   +-->	x = a7		// PIC16
//          x = a7_i	// (PIC18, PIC24, dsPIC33)
//	          |
//	          +-->	x = PORTAbits.PORTA7
#define pin__read(PIN_NAME)  PIN_NAME ## _i