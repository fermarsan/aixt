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
pub fn write(PIN_NAME,VAL) {
	C.PIN_NAME = VAL        // LATBbits.LB0 = 0
}