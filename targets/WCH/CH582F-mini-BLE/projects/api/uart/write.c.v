// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH582F)

module uart

@[inline]
pub fn write(DATA) {
	C.R8_UART0_THR = DATA
}