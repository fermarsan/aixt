// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: PRINTLN functions (STM32F103C)
//              (PC port) 

module uart

#define uart.println(MESSAGE)   Serial.println(MESSAGE)
