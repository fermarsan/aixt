// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
//
// ## Description
// PIN management functions  (PIC18F2550 port)

module pin_fn

@[inline]
pub fn write(id u8, value u8) {
	C.PIN_NAME = VAL        // LATBbits.LB0 = 0
}
