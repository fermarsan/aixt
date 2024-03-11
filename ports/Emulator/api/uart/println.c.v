// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module uart

#define uart__println_0(MESSAGE)	printf("\033[1;32m");	printf("%s\n", MESSAGE)	// in green

#define uart__println_1(MESSAGE)	printf("\033[1;31m");	printf("%s\n", MESSAGE)	// in red

#define uart__println_2(MESSAGE)	printf("\033[1;34m");	printf("%s\n", MESSAGE)	// in blue

#define uart__println_x(UART_NUMBER, MESSAGE)		uart__println_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments
#define SEL_UART_PRINTLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__println(...) SEL_UART_PRINTLN(__VA_ARGS__, uart__println_x, uart__println_0)(__VA_ARGS__)
