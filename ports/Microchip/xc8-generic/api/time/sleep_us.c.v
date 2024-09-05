// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Authors: 
//	- Luis Alfredo Pinto Medina
//	- Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: microseconds delay function (PIC16F84A port)
module time

// sleep_us function does a delay in microseconds
@[inline]
pub fn sleep_us(tus u16) {
	C.__delay_us(tus)
}