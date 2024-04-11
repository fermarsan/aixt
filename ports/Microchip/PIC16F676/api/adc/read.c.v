// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F676 port)

module adc

fn read(channel u8) u16 {

    ADCON0bits.CHS = channel      // Asigna el canal del ADC  
    ADCON0bits.GO_DONE = 1             // Inicia la conversion
    for ADCON0bits.GO_DONE == 1 {}
    return ((ADRESH << 8) | ADRESL) /* Devuelve el valor del ADC */
   }




/*
#define adc__read(CHANNEL) \
    ADCON0bits.CHS = CHANNEL /* Asigna el canal del ADC */ \
    ADCON0bits.GO_DONE = 1   /* Inicia la conversión */ \
    while (ADCON0bits.GO_DONE == 1) /* Espera a que la conversión termine */ \
    adc_result = (ADRESH << 8) | ADRESL /* Devuelve el valor del ADC */\
    adc_result /* Devuelve el valor del ADC a la variable asignada*/
*/