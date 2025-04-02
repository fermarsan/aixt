// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: uart.read functions (Ai_Thinker_Ai-WB2-32S-Kit)

module uart

@[inline]
pub fn read() {
	C.Serial.read()
}

//@[inline]
pub fn read_1() {
	C.Serial1.read()
}

//@[inline]
pub fn read_x(UART_NUMBER) {
	C.uart.read_ ## UART_NUMBER ## .read()
}

// macro with 0 or 1 arguments
//#define SEL_uart.read(_0, _1, MACRO_NAME, ...) MACRO_NAME
//@[inline]
pub fn read(...) SEL_uart.read(_0 __VA_OPT__(,) {
	C.__VA_ARGS__, uart.read_x, uart.read_0)(__VA_ARGS__)
}