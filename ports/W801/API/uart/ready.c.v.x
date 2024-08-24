// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: ready.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

#define uart__ready_0()	Serial.ready()

#define uart__ready_1()	Serial1.ready()

#define uart__ready_x(UART_NUMBER)	uart__ready_ ## UART_NUMBER ## .ready()

// macro with 0 or 1 arguments
#define SEL_UART_READY(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart__read(...) SEL_UART_READY(_0 __VA_OPT__(,) __VA_ARGS__, uart__ready_x, uart__ready_0)(__VA_ARGS__)