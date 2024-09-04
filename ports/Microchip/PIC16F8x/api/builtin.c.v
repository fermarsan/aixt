// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (PIC16F8x port)

module main

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "builtin.c"

__global (
	addr = &u8(0)
)