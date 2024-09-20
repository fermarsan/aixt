// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: uart.println functions (Ai_Thinker_Ai-WB2-32S-Kit)

module uart

@[inline]
pub fn println(MESSAGE) {
	C.Serial.println(MESSAGE)
}

//@[inline]
pub fn println_1(MESSAGE) {
	C.Serial1.println(MESSAGE)
}

//@[inline]
pub fn println_x(UART_NUMBER, MESSAGE)		uart.println_ ##  UART_NUMBER (MESSAGE) {
	C.	
}

// macro with 1 or 2 arguments
//#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
//@[inline]
pub fn println(...) {
	C.SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)
}