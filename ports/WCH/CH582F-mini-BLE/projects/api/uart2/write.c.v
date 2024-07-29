// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART2 functions (WCH-CH582F)

module uart2

#define	uart2__write(DATA)	 R8_UART2_THR = DATA