// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Authors: 
//	- Luis Alfredo Pinto Medina
//	- Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: microseconds delay function (PIC16F84A port)
module time

#include "sleep_us.c"

// sleep_us function does a delay in microseconds
pub fn sleep_us(ts u16)