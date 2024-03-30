// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: PIN functions (Blue Pill_AIR32F103C)
//              (PC port) 

#define pin_setup(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)

#define pin_high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)

#define pin_low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)

#define out OUTPUT

#define in INPUT_PULLUP

#define pin_read(PIN_NAME)   digitalRead(PIN_NAME)