// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: high.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: HIGH functions (Blue Pill_STM32F103C)
//              (PC port) 

module pin

#define pin__high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)