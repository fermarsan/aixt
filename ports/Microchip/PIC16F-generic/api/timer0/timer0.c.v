// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Timer0 functions for 16F family
module timer0

#include "timer0.c"

__global (
	timer0__prescaler = i8(7)
	timer0__initial = i8(-1)
)