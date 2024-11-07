// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)

module adc

fn read(channel u16) u16 {
    ADCON0bits.CHS = channel // Asigna el canal del ADC
    ADCON0bits.GO_DONE = 1 // Inicia la conversión
    for ADCON0bits.GO_DONE == 1 {} // Espera a que la conversión termine
    return (ADRESH << 8) | ADRESL // Devuelve el valor del ADC
}

