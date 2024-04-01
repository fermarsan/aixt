// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup_1.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP_1 functions (STM32F103C)
//              (PC port) 

module uart

#define uart__setup_1(BAUD_RATE)   Serial1.begin(BAUD_RATE)
