// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module adc

#include <stdio.h>
#include <stdlib.h>

// read is the reading function for emulated ADC
// receive as parameter the ADC channel 
pub fn read(channel int) int {
    adc__value := 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
    C.printf(' Aixt virtual ADC input     ADC %ld : ', channel)
    C.scanf('%ld', &adc__value)
    return adc__value
}