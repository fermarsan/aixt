// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART1 functions (WCH-CH582F)

module uart1

@[inline]
pub fn uart1.any() {
	C.R8_UART1_RFC 
}