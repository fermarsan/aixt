// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// PIN functions (WCH-CH573F)

module pin

@[inline]
pub fn high_(port, ...) {
	C.GPIO##port##_SetBits(GPIO_Pin_##__VA_ARGS__)
}

@[inline]
pub fn high(PIN_NAME) {
	C.pin.high_(PIN_NAME)
}
