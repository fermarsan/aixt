module uart

@[inline]
pub fn setup(BAUD_RATE) {
	C.Serial.begin(BAUD_RATE)
}


@[inline]
pub fn setup_0(BAUD_RATE) {
	C.Serial.begin(BAUD_RATE)
}
@[inline]
pub fn setup_1(BAUD_RATE) {
	C.Serial1.begin(BAUD_RATE)
}
@[inline]
pub fn setup_x(UART_NUMBER, BAUD_RATE)		uart.setup_ ## UART_NUMBER (BAUD_RATE) {
	C.	
}

// macro with 1 or 2 arguments
#define SEL_uart.setup(_1, _2, MACRO_NAME, ...) MACRO_NAME
@[inline]
pub fn setup(...) {
	C.SEL_uart.setup(__VA_ARGS__, uart.setup_x, uart.setup_0)(__VA_ARGS__)
}