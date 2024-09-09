// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: LOW functions (Blue Pill_STM32F103C)
//              (PC port) 

module pin

#define pin__low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)