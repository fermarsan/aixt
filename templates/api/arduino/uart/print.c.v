module uart


@[inline]
pub fn print_0(MESSAGE) {
	C.Serial.print(MESSAGE)
}

@[inline]
pub fn print_1(MESSAGE) {
	C.Serial1.print(MESSAGE)
}

@[inline]
pub fn print_x(UART_NUMBER, MESSAGE)		uart.print_ ## UART_NUMBER (MESSAGE) {
	C.	
}

// macro with 1 or 2 arguments
#define SEL_uart.print(_1, _2, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn print(...) {
	C.SEL_uart.print(__VA_ARGS__, uart.print_x, uart.print_0)(__VA_ARGS__)
}