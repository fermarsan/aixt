// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm.c
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: PWM functions (Blue-Pill)
//              (PC port) 

#define pwm__write(PIN_NAME, MODE)   pwmWrite(PIN_NAME, MODE)

#define pwm__map(MODE, VALUE,VALUE1,VALUE2,VALUE3)   map(MODE, VALUE,VALUE1,VALUE2,VALUE3)