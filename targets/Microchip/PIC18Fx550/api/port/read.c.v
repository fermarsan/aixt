// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo y Fernando M. Santa
//
// _Date:_ 2024
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