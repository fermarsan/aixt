// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F886 port)
module adc

#include "read.c"

fn C.read(channel u8) u16