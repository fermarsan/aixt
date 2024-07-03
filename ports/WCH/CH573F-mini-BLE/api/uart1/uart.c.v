// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART1 functions (WCH-CH573F)

module uart1

#define uart1__println(MSG)		uart1__print(MSG);  uart1__write('\n');  uart1__write('\r')