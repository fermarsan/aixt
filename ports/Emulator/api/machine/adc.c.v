// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
#include <stdio.h>
#include <stdlib.h>

__global (
    value__ = 0
)

fn adc1_read() int {
    system('clear')
    printf(' Aixt virtual ADC input     ADC 1 : ')
    scanf('%d', &value__)
    return value__
}

fn adc2_read() int {
    system('clear')
    printf(' Aixt virtual ADC input     ADC 2 : ')
    scanf('%d', &value__)
    return value__
}