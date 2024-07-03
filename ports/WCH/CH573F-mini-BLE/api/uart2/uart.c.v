// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART2 functions (WCH-CH573F)

module uart2

#define uart2__println(MSG)		uart2__print(MSG);  uart2__write('\n');  uart2__write('\r')