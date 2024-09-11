// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP functions (STM32F103C)
//              (PC port) 

module uart

@[inline]
pub fn uart.setup(BAUD_RATE) {
	C.Serial.begin(BAUD_RATE)
}
