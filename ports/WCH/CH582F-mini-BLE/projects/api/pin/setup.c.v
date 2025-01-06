// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

@[inline]
pub fn setup_(port, pin, ...) {
	C.GPIO##port##_ModeCfg(GPIO_Pin_##pin, ##__VA_ARGS__)
}

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
}
