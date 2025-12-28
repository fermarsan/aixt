// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// PIN management functions  (PIC18F2550 port)

module pin_fn

@[inline]
pub fn high(PIN_NAME) {
	C.PIN_NAME = 1          // LATBbits.LB0 = 1
}