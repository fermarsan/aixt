// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART1 functions (WCH-CH582F)

module uart1

@[inline]
pub fn uart1.write(DATA) {
C.R8_UART1_THR = DATA
}