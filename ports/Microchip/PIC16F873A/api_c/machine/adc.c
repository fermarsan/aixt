// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: adc functions
//              (PIC16F873A port)




unsigned int adc_setup() {
    ADCON1 = 0b10000000; 
    ADCON0 = 0b11001000;
    ADCON0bits.ADON = 1;
}


unsigned int adc_read( unsigned int channel) {
    ADCON0bits.CHS = channel; // Asigna el canal del ADC
    ADCON0bits.GO_DONE = 1; // Inicia la conversión
    while (ADCON0bits.GO_DONE == 1); // Espera a que la conversión termine
    return (ADRESH << 8) | ADRESL; // Devuelve el valor del ADC
}