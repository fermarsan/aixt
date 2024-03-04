// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: reading.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

module adc

fn reading() u16 {
        ADCON0bits.GO_DONE = 1             // Inicia la conversion
        for (ADCON0bits.GO_DONE == 1) {}   // Espera a que termine la conversion
        return ((ADRESH << 8) + ADRESL)    
    }