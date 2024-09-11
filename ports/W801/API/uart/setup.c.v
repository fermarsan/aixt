// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart


#define uart.setup_0(BAUD_RATE)					Serial.begin(BAUD_RATE)

#define uart.setup_1(BAUD_RATE)					Serial1.begin(BAUD_RATE)

#define uart.setup_x(UART_NUMBER, BAUD_RATE)		uart.setup_ ## UART_NUMBER (BAUD_RATE) 			

// macro with 1 or 2 arguments
#define SEL_uart.setup(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart.setup(...) SEL_uart.setup(__VA_ARGS__, uart.setup_x, uart.setup_0)(__VA_ARGS__)