// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

module adc

fn read(channel u8) int {
    ADCON0bits.CHS = channel      // Asigna el canal del ADC  
    ADCON0bits.GO_DONE = 1             // Inicia la conversion
    for (ADCON0bits.GO_DONE == 1) {}   // Espera a que termine la conversion
    return ADRES   
}