// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Javier Leon, Camilo Lucas and Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (CY8CKIT-145-40XX)

@[inline]
pub fn pin.high(pin_name) {
	C.pin.write(pin_name, 0)
}
@[inline]
pub fn pin.low(pin_name) {
	C.pin.write(pin_name, 1)
}

@[inline]
pub fn pwm.write(pin_name, value) {
	C.pin_name##_Write(!value)
}
@[inline]
pub fn pin.read(pin_name) {
	C.pin_name##_Read()
}
