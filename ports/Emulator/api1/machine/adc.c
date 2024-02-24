// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
#include <stdio.h>
#include <stdlib.h>

int __value = 0;

int adc1_read() {
    system("clear");
    printf(" Aixt virtual ADC input     ADC 1 : ");
    scanf("%d", &__value);
    return __value;
}

int adc2_read() {
    system("clear");
    printf(" Aixt virtual ADC input     ADC 2 : ");
    scanf("%d", &__value);
    return __value;
}andcagual