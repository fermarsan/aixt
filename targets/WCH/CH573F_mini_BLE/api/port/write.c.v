// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

@[inline]
pub fn write_(PORT, BITS) {
	C.GPIO##PORT##_SetBits(BITS)
}

@[inline]
pub fn write(PORT, BITS) {
	C.port.write_(PORT, BITS)
}
