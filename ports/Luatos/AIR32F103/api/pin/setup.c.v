// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP functions (Blue Pill_AIR32F103C)
//              (PC port) 

module pin

#define pin__setup(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)