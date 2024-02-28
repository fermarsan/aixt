module uart


#define uart__println_0(MESSAGE)	Serial.println(MESSAGE)

#define uart__println_1(MESSAGE)	Serial1.println(MESSAGE)

#define uart__println_x(UART_NUMBER, MESSAGE)		uart__println_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments
#define SEL_UART_PRINTLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__println(...) SEL_UART_PRINTLN(__VA_ARGS__, uart__println_x, uart__println_0)(__VA_ARGS__)