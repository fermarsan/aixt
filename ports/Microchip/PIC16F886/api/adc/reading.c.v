// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: reading.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F886 port)

module adc

fn adc__reading() u16 {
    ADCON0bits.GO_DONE = 1 /* Inicia la conversión */ 
    for ADCON0bits.GO_DONE == 1 {}/* Espera a que la conversión termine */
    return (ADRESH << 8) | ADRESL /* Devuelve el valor del ADC */
}