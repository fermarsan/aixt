// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Authors: 
//	- Luis Alfredo Pinto Medina
//	- Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: milliseconds delay function (PIC16F84A port)
module time

#include "sleep_ms.c"

// sleep_ms function does a delay in milliseconds
pub fn sleep_ms(ts u16)