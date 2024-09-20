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
pub fn println_x(UART_NUMBER, MESSAGE)		uart.println_ ## UART_NUMBER (MESSAGE) {
	C.	
}

// macro with 1 or 2 arguments
#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn println(...) {
	C.SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)
}