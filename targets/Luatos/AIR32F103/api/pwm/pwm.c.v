// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// // Description: PWM functions (Blue Pill_STM32F103C)
//              (PC port) 

module pwm

@[inline]
pub fn write(PIN_NAME, MODE) {
	C.pwmWrite(PIN_NAME, MODE)
}

@[inline]
pub fn map(MODE, VALUE,VALUE1,VALUE2,VALUE3) {
	C.map(MODE, VALUE,VALUE1,VALUE2,VALUE3)
}

