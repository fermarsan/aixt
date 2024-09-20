module uart


@[inline]
pub fn any_0() {
	C.Serial.available()
}

@[inline]
pub fn any_1() {
	C.Serial1.available()
}

@[inline]
pub fn any_x(UART_NUMBER) {
	C.uart.any_ ## UART_NUMBER ## .available()
}

// macro with 0 or 1 arguments
#define SEL_UART_ANY(_0, _1, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn any(...) SEL_UART_ANY(_0 __VA_OPT__(,) {
	C.__VA_ARGS__, uart.any_x, uart.any_0)(__VA_ARGS__)
}