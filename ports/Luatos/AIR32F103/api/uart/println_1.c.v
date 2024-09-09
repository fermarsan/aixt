// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: println_1.c.v
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: PRINTLN functions (STM32F103C)
//              (PC port) 

module uart

#define uart__println_1(MESSAGE)   Serial1.println(MESSAGE)
