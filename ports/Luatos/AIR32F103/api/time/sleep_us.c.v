// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// // Description: SLEEP_us functions (Blue Pill_STM32F103C)
//              (PC port) 

module time

#define time.sleep_us(US)    delayMicroseconds(US)