// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
module adc

__global (
    adc__value = 0
)

#define adc__ch0    0
#define adc__ch1    1