// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F886 port)

module adc

#define adc__read(channel) \
    ADCON0bits.CHS = channel /* Asigna el canal del ADC */ \
    adc_reading() /* Función para retornar el valor del ADC*/ 