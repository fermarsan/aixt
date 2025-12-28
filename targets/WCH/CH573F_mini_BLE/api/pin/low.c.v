// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// PIN functions (WCH-CH573F)

module pin

@[inline]
pub fn low_(port, ...) {
	C.GPIO##port##_ResetBits(GPIO_Pin_##__VA_ARGS__)
}

@[inline]
pub fn low(PIN_NAME) {
	C.pin.low_(PIN_NAME)
}
