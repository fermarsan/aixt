// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc_reading.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC_READING
//              (PIC18F452)
module adc
fn      reading() u16 {
        ADCON0bits.GO_DONE = 1             // Inicia la conversion
        for (ADCON0bits.GO_DONE == 1)  {}   // Espera a que termine la conversion
        return ((ADRESH << 8) + ADRESL) }