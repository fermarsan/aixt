// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo y Fernando M. Santa
// Date: 2024
// License: MIT

module port

// setup macro configures a complete pin port input/output mode. This is expanded in this way:
//   pin.setup(pin.a, value)
//     |
//	   +-->	TRISa = value
//            |
//	          +-->	TRISA = value

@[inline]
pub fn setup(PORT_NAME, VALUE) {
	C.TRIS ## PORT_NAME = VALUE
}
