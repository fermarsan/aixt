// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: print.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

#define uart__print_0(MESSAGE)	Serial.print(MESSAGE)

#define uart__print_1(MESSAGE)	Serial1.print(MESSAGE)

#define uart__print_x(UART_NUMBER, MESSAGE)		uart__print_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments
#define SEL_UART_PRINT(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__print(...) SEL_UART_PRINT(__VA_ARGS__, uart__print_x, uart__print_0)(__VA_ARGS__)