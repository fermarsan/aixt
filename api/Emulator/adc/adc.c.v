// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
//
// ## Description
// This is a module to emulate ADC inputs in console.
module adc

#include <stdio.h>
#include <stdlib.h>

pub const ch0 = 0 // ADC channel ids
pub const ch1 = 1

// read is the reading function for the emulated ADC.
// This receives as parameter the ADC `channel` id
pub fn read(channel int) int {
    adc_value := 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
    C.printf(' Aixt virtual ADC input     ADC %d : ', channel)
    C.scanf('%d', &adc_value)
    return adc_value
}
