// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Javier Leon, Camilo Lucas and Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
//              (CY8CKIT-049-42XX)

@[inline]
pub fn pin.high(pin_name) {
	C.pin.write(pin_name, 1)
}
@[inline]
pub fn pin.low(pin_name) {
	C.pin.write(pin_name, 0)
}

@[inline]
pub fn pwm.write(pin_name, value) {
	C.pin_name##_Write(value)
}
@[inline]
pub fn pin.read(pin_name) {
	C.pin_name##_Read()
}
