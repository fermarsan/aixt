// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela y Fernando M. Santa
//
// _Date:_ 2024
// License: MIT

module port

// setup macro configures a complete pin port input/output mode. This is expanded in this way:
//   pin.setup(pin.a, value)
//     |
//	   +-->	TRISa = value
//            |
//	          +-->	TRISA = value

@[inline]
pub fn setup(id u8, value u8) {
	C.TRIS //## PORT_NAME = VALUE
}
