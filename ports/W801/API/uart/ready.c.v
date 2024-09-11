// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

@[inline]
pub fn ready_0() {
	C.Serial.ready()
}

@[inline]
pub fn ready_1() {
	C.Serial1.ready()
}

@[inline]
pub fn ready_x(UART_NUMBER) {
	C.uart.ready_ ## UART_NUMBER ## .ready()
}

// macro with 0 or 1 arguments
#define SEL_uart.readY(_0, _1, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn read(...) SEL_uart.readY(_0 __VA_OPT__(,) {
	C.__VA_ARGS__, uart.ready_x, uart.ready_0)(__VA_ARGS__)
}