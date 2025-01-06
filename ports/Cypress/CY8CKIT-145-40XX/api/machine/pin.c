// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//	- Javier Leon
//	- Camilo Lucas
//	- Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (CY8CKIT-145-40XX)

@[inline]
pub fn high(pin_name) {
	C.pin.write(pin_name, 0)
}
@[inline]
pub fn low(pin_name) {
	C.pin.write(pin_name, 1)
}

@[inline]
pub fn write(pin_name, value) {
	C.pin_name##_Write(!value)
}
@[inline]
pub fn read(pin_name) {
	C.pin_name##_Read()
}
