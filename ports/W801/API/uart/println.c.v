// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

@[inline]
pub fn println_0(MESSAGE) {
	C.Serial.println(MESSAGE)
}

@[inline]
pub fn println_1(MESSAGE) {
	C.Serial1.println(MESSAGE)
}

@[inline]
pub fn println_2(MESSAGE) {
	C.Serial2.println(MESSAGE)
}

@[inline]
pub fn println_3(MESSAGE) {
	C.Serial3.println(MESSAGE)
}

@[inline]
pub fn println_4(MESSAGE) {
	C.Serial4.println(MESSAGE)
}

@[inline]
pub fn println_5(MESSAGE) {
	C.Serial5.println(MESSAGE)
}

@[inline]
pub fn println_x(UART_NUMBER, MESSAGE)		uart.println_ ## UART_NUMBER (MESSAGE) {
	C.	
}

// macro with 1 or 2 arguments
#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn println(...) {
	C.SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)
}