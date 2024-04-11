// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_ms.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SLEEP_ms functions (Blue-Pill)
//              (PC port) 

module time

#define time__sleep_ms(MS)    delay(MS)