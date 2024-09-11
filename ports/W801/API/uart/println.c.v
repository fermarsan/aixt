// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

#define uart.println_0(MESSAGE)	Serial.println(MESSAGE)

#define uart.println_1(MESSAGE)	Serial1.println(MESSAGE)

#define uart.println_2(MESSAGE)	Serial2.println(MESSAGE)

#define uart.println_3(MESSAGE)	Serial3.println(MESSAGE)

#define uart.println_4(MESSAGE)	Serial4.println(MESSAGE)

#define uart.println_5(MESSAGE)	Serial5.println(MESSAGE)

#define uart.println_x(UART_NUMBER, MESSAGE)		uart.println_ ## UART_NUMBER (MESSAGE) 			

// macro with 1 or 2 arguments
#define SEL_uart.printLN(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart.println(...) SEL_uart.printLN(__VA_ARGS__, uart.println_x, uart.println_0)(__VA_ARGS__)