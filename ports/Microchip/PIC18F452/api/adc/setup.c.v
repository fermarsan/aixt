// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC SETUP
//              (PIC18F452)
module adc
fn setup() {
    ADCON1 = 0xC0 /* Ajusta todos los canales como analogicos */ 
    ADCON0 = 0xC0 /* Ajusta todos las entradas como analogicos */
    ADCON0bits.ADON = 1
    }