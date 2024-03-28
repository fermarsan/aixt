// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git
// File Name: read.c.v
// Author: Fernando Martinez Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module uart 

#define uart__read_0()	Serial.read()

#define uart__read_1()	Serial1.read()

#define uart__read_x(UART_NUMBER)	uart__read_ ## UART_NUMBER ## .read()

// macro with 0 or 1 arguments
#define SEL_UART_READ(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart__read(...) SEL_UART_READ(_0 __VA_OPT__(,) __VA_ARGS__, uart__read_x, uart__read_0)(__VA_ARGS__)