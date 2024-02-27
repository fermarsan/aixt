module uart

#define uart__println(MESSAGE)   Serial.println(MESSAGE)

#define uart__println(UART_NUMBER, MESSAGE)   Serial ## UART_NUMBER ## .println(MESSAGE)

