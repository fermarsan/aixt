// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela y Fernando Martínez Santa
// Date: 2024
// License: MIT

module port

// setup macro configures a complete pin port input/output mode. This is expanded in this way:
//   pin.setup(a, value)
//     |
//	   +-->	TRISa = value
//            |
//	          +-->	TRISA = value

#define port__setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE
