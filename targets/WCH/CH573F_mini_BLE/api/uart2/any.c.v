// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// UART2 functions (WCH-CH573F)

module uart2

@[inline]
pub fn uart2.any() {
	C.R8_UART2_RFC 
}