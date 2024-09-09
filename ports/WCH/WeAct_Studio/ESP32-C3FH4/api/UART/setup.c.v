// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git
// File Name: setup.c.v
// Author: Farith Ochoa Leon, Felipe Cardozo and Fernando Martinez Santa
// Date: 2024
// License : MIT

module uart 

#define uart__setup(BAUD_RATE)  				    Serial.begin(BAUD_RATE)

#define uart__setup_0(BAUD_RATE)					Serial.begin(BAUD_RATE)

#define uart__setup_1(BAUD_RATE)					Serial1.begin(BAUD_RATE)

#define uart__setup_x(UART_NUMBER, BAUD_RATE)		uart__setup_ ## UART_NUMBER (BAUD_RATE) 			

// macro with 1 or 2 arguments

#define SEL_uart.setup(_1, _2, MACRO_NAME, ...) MACRO_NAME
#define uart__setup(...) SEL_uart.setup(__VA_ARGS__, uart__setup_x, uart__setup_0)(__VA_ARGS__)