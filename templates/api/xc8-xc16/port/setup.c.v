// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 2
// License: MIT
module port

// setup macro configures a complete pin port input/output mode. This is expanded in this way:
//   pin.setup(a, value)
//     |
//	   +-->	TRISa = value
//            |
//	          +-->	TRISA = value
@[inline]
pub fn setup(PORT_NAME, VALUE) {
	C.TRIS ## PORT_NAME = VALUE
}
