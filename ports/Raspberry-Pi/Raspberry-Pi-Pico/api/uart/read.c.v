module uart


#define uart.read_0()	Serial.read()

#define uart.read_1()	Serial1.read()

#define uart.read_x(UART_NUMBER)	uart.read_ ## UART_NUMBER ## .read()

// macro with 0 or 1 arguments
#define SEL_uart.read(_0, _1, MACRO_NAME, ...) MACRO_NAME
#define uart.read(...) SEL_uart.read(_0 __VA_OPT__(,) __VA_ARGS__, uart.read_x, uart.read_0)(__VA_ARGS__)