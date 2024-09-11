// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: READ functions (Blue Pill_STM32F103C)
//              (PC port) 

module pin

#define pin.read(PIN_NAME)   digitalRead(PIN_NAME)