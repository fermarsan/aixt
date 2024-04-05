// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// read macro reads the value of an input pin. This is expanded in this way:
//   x = pin.read(a7)
//     |
//	   +-->	x = pin.read(A, 7)		
//	          |
//	          +-->	x = PORTAbits.PORTA7	// (PIC16, PIC18, PIC24, dsPIC33)
#define pin__read_(PORT_NAME, PIN)	PORT ## PORT_NAME ## bits.PORT ## PORT_NAME ## PIN

#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)