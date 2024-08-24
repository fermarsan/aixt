module uart// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: any.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart4


@[inline]
pub fn uart.any_0()	Serial.available()

@[inline]
pub fn uart.any_1()	Serial1.available()

@[inline]
pub fn uart.any_x(UART_NUMBER)	uart.any_ ## UART_NUMBER ## .available()

// macro with 0 or 1 arguments
@[inline]
pub fn SEL_UART_ANY(_0, _1, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn uart.any(...) SEL_UART_ANY(_0 __VA_OPT__(,) __VA_ARGS__, uart__any_x, uart__any_0)(__VA_ARGS__)