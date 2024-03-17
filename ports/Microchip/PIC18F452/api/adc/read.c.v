// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc_read.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC_READ
//              (PIC18F452)
module adc
fn read(channel u8) int { 
    ADCON0bits.CHS = channel /* Asigna el canal del ADC */ 
    ADCON0bits.GO_DONE = 1             // Inicia la conversion
    for (ADCON0bits.GO_DONE == 1)  {}   // Espera a que termine la conversion
    return ADRES
}