// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart


@[inline]
pub fn uart.read_0() {
	C.Serial.read()
}

@[inline]
pub fn uart.read_1() {
	C.Serial1.read()
}

@[inline]
pub fn uart.read_x(UART_NUMBER) {
	C.uart.read_ ## UART_NUMBER ## .read()
}

// macro with 0 or 1 arguments
#define SEL_uart.read(_0, _1, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn uart.read(...) SEL_uart.read(_0 __VA_OPT__(,) {
	C.__VA_ARGS__, uart.read_x, uart.read_0)(__VA_ARGS__)
}

