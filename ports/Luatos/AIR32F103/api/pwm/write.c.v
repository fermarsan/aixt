// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: WRITE functions (Blue Pill_STM32F103C)
//              (PC port) 

module pwm

#define pwm__write(PIN_NAME, MODE)   analogWrite(PIN_NAME, MODE)