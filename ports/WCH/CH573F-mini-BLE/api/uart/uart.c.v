// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH573F)

module uart 

@[inline]
pub fn println(MSG) {
	C.uart.print(MSG);  uart.write('\n');  uart.write('\r')
}