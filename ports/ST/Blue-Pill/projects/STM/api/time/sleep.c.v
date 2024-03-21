// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SLEEP functions (Blue Pill_STM32F103C)
//              (PC port) 

module time

#define time__sleep(S)    delay(S*1000)