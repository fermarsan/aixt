
#define uart__println_0(MESSAGE)    uart__println_x(0, MESSAGE)
#define SEL_UART_PRINTLN(_1, _2, MACRO_NAME, ...)   MACRO_NAME
#define uart__println(...)  SEL_UART_PRINTLN(__VA_ARGS__, uart__println_x, uart__println_0)(__VA_ARGS__)