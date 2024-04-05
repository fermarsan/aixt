// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: WRITE functions (Blue-Pill)
//              (PC port) 

module pwm

#define pwm__write(PIN_NAME, MODE)   pwmWrite(PIN_NAME, MODE)