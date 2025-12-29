// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// PORT functions (WCH-CH582F)

module port

@[inline]
pub fn write_(PORT, BITS) {
	C.GPIO##PORT##_SetBits(BITS)
}

@[inline]
pub fn write(PORT, BITS) {
	C.port.write_(PORT, BITS)
}
