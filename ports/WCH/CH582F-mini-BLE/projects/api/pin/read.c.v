// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

@[inline]
pub fn pwm.read_(port, ...) {
	C.GPIO##port##_ReadPortPin(GPIO_Pin_##__VA_ARGS__)
}

@[inline]
pub fn pin.read(PIN_NAME) {
	C.pin.read_(PIN_NAME)
}