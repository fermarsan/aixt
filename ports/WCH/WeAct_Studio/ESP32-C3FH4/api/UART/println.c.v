// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Farith Ochoa Leon, Felipe Cardozo and Fernando M. Santa
// Date: 2024
// License : MIT

module uart 

@[inline]
pub fn uart.println_0(MESSAGE) {
	C.Serial.println(MESSAGE)
}
@[inline]
pub fn uart.print(MESSAGE) {
	C.Serial.print(MESSAGE)
}
@[inline]
pub fn uart.println_1(MESSAGE) {
	C.Serial1.println(MESSAGE)
}

@[inline]
pub fn uart.println_x(UART_NUMBER, MESSAGE)		uart.println_ ## UART_NUMBER (MESSAGE) {
	C.	
}

// macro with 1 or 2 arguments

#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn uart.println(...) {
	C.SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)
}