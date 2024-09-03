// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: microseconds delay function (PIC16F84A port)
module time

// sleep_ms function does a delay in microseconds
@[inline]
pub fn sleep(ts u16) {
	C.__delay_us(ts)
}