// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git
// File Name: any.c.v
// Author: Fernando Martinez Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module uart 

#define uart__any_0()	Serial.available()

#define uart__any_1()	Serial1.available()

#define uart__any_x(UART_NUMBER)	uart__any_ ## UART_NUMBER ## .available()

// macro with 0 or 1 arguments
#define SEL_UART_ANY(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart__any(...) SEL_UART_ANY(_0 __VA_OPT__(,) __VA_ARGS__, uart__any_x, uart__any_0)(__VA_ARGS__)