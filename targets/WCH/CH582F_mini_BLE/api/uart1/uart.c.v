// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Cristian Garzón
//
// _Date:_ 2023 - 2024
// ## Description
// UART1 functions (WCH-CH582F)

module uart1

@[inline]
pub fn uart1.println(MSG) {
C.uart1.print(MSG);  uart1.write('\n');  uart1.write('\r')
}