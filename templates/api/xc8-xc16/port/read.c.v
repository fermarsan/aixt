// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
module port

// read macro reads the value of a complete pin port. This is expanded in this way:
//   x = port.read(a)
//     |
//	   +-->	x = PORTa
//            |
//	          +-->	x = PORTA
@[inline]
pub fn read(PORT_NAME) {
C.PORT ## PORT_NAME
}