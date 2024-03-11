// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module uart

#define uart__print_0(MESSAGE)		printf("\033[1;32m");	printf("%s", MESSAGE)	// in green

#define uart__print_1(MESSAGE)		printf("\033[1;31m");	printf("%s", MESSAGE)	// in red

#define uart__print_2(MESSAGE)		printf("\033[1;34m");	printf("%s", MESSAGE)	// in blue

#define uart__print_x(UART_NUMBER, MESSAGE)		uart__print_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments
#define SEL_UART_PRINT(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__print(...) SEL_UART_PRINT(__VA_ARGS__, uart__print_x, uart__print_0)(__VA_ARGS__)

