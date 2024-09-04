// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Authors: 
//	- Luis Alfredo Pinto Medina
//	- Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function (PIC16F84A port)
module time

#include "sleep.c"

// sleep function does a delay in seconds
pub fn sleep(ts u16) 