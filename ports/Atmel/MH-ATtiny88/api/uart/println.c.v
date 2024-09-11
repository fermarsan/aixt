// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Fernando M. Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module uart 

#define uart.println_0(MESSAGE)	Serial.println(MESSAGE)
#define uart.print(MESSAGE)        Serial.print(MESSAGE)
#define uart.println_1(MESSAGE)	Serial1.println(MESSAGE)

#define uart.println_x(UART_NUMBER, MESSAGE)		uart.println_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments

#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart.println(...) SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)
