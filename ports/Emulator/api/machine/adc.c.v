// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
#include <stdio.h>
#include <stdlib.h>

__value := 0

fn adc1_read() int {
    system('clear')
    printf(' Aixt virtual ADC input     ADC 1 : ')
    scanf('%d', &__value)
    return __value
}

fn adc2_read() int {
    system('clear')
    printf(' Aixt virtual ADC input     ADC 2 : ')
    scanf('%d', &__value)
    return __value
}