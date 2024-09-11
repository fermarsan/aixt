// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

@[inline]
pub fn port.write_(PORT, BITS) {
	C.GPIO##PORT##_SetBits(BITS)
}

@[inline]
pub fn port.write(PORT, BITS) {
	C.port.write_(PORT, BITS)
}
