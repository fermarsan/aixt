// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F886 port)

module adc

#define adc__setup()  ADCON1 = 0b10000000;  ADCON0 = 0b11001000;  ADCON0bits.ADON = 1;

/*
#define adc__setup() \
    ADCON1 = 0b10000000 /* se configuran todos los puertos como analogicos */ \
    ADCON0 = 0b11001000 /* se configuran todas las entradas como analogicas */\
    ADCON0bits.ADON = 1
*/