// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// PIN functions (WCH-CH582F)

module pin

@[inline]
pub fn setup_(port, pin, ...) {
	C.GPIO##port##_ModeCfg(GPIO_Pin_##pin, ##__VA_ARGS__)
}

@[inline]
pub fn setup(id u8, mode u8) {
	C.pin.setup_(id u8, mode u8)
}
