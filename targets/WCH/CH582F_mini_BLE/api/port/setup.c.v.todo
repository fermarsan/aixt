// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// PORT functions (WCH-CH582F)

module port

@[inline]
pub fn setup_(PORT, BITS, MODE) {
	C.GPIO##PORT##_ModeCfg(BITS, MODE)
}

@[inline]
pub fn setup(PORT, BITS, MODE) {
	C.port.setup_(PORT, BITS, MODE)
}

	