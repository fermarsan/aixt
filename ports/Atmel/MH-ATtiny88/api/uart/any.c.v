// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Fernando M. Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module uart 

#define uart.any_0()	Serial.available()

#define uart.any_1()	Serial1.available()

#define uart.any_x(UART_NUMBER)	uart.any_ ## UART_NUMBER ## .available()

// macro with 0 or 1 arguments
#define SEL_UART_ANY(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart.any(...) SEL_UART_ANY(_0 __VA_OPT__(,) __VA_ARGS__, uart.any_x, uart.any_0)(__VA_ARGS__)