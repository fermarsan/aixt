module uart

#define uart__ready()   Serial.available()

#define uart__ready(UART_NUMBER)		Serial ## UART_NUMBER ## .ready()