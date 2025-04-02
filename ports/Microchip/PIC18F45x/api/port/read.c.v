// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela y Fernando M. Santa
// Date: 2024
// License: MIT

module port

// read macro reads the value of a complete pin port. This is expanded in this way:
//   x = port.read(port.a)
//     |
//	   +-->	x = PORTa
//            |
//	          +-->	x = PORTA

@[inline]
pub fn read(PORT_NAME) {
C.PORT ## PORT_NAME
}