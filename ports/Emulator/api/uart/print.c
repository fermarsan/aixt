
#define uart__print_0(MESSAGE)      uart__print_x(0, MESSAGE)
#define SEL_UART_PRINT(_1, _2, MACRO_NAME, ...)     MACRO_NAME
#define uart__print(...)    SEL_UART_PRINT(__VA_ARGS__, uart__print_x, uart__print_0)(__VA_ARGS__)