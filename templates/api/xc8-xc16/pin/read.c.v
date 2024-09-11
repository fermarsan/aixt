// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
module pin

// read macro reads the value of an input pin. This is expanded in this way:
//   x = pin.read(a7)
//     |
//	   +-->	x = pin.read(A, 7)		
//	          |
//	          +-->	x = PORTAbits.PORTA7	// (PIC16, PIC18, PIC24, dsPIC33)
@[inline]
pub fn read_(PORT_NAME, PIN) {
	C.PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN
}

@[inline]
pub fn read(PIN_NAME) {
	C.pin.read_(PIN_NAME)
}