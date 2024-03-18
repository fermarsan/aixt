// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP functions (STM32F103C)
//              (PC port) 

module uart

#define uart__setup(BAUD_RATE)   Serial.begin(BAUD_RATE)
