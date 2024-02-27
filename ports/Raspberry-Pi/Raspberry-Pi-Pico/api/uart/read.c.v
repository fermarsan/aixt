module uart

#define uart__read()   				Serial.read()

#define uart__read(UART_NUMBER)		Serial ## UART_NUMBER ## .read()