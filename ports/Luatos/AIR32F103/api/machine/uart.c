// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: UART functions (Blue Pill_STM32F103C)
//              (PC port) 

#define uart0__setup(baud_rate)   Serial.begin(baud_rate)
#define uart.setup(baud_rate)   Serial.begin(baud_rate)

#define uart0__ready()  Serial.available()
#define uart.ready()   Serial.available()

#define uart0__read()   Serial.read()
#define uart.read()   Serial.read()

#define println(message)   Serial.println(message)