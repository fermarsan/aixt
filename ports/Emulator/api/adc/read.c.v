// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module adc

#include <stdio.h>
#include <stdlib.h>

#include "read.c"

// read is the reading function for emulated ADC
// receive as parameter the ADC channel 
pub fn read(channel int) int
