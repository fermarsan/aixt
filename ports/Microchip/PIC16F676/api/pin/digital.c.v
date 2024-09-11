// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Digital management functions
//              (PIC16F676 port)

module pin 

@[inline]
pub fn pwm.digital() {
	C.ANSEL = 0
}

