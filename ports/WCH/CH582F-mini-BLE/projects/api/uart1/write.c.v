// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART1 functions (WCH-CH582F)

module uart1

#define	uart1__write(DATA)	 R8_UART1_THR = DATA