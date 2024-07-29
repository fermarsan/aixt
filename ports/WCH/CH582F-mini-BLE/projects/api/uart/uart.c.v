// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH582F)

module uart 

#define uart__println(MSG)		uart__print(MSG);  uart__write('\n');  uart__write('\r')