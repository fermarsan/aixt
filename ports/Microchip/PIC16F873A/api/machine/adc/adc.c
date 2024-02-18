// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F873A port)

#define adc_setup() \
    ADCON1 = 0b10000000; /* Ajusta todos los canales como analogicos */ \
    ADCON0 = 0b11001000; /* Ajusta todos las entradas como analogicos */\
    ADCON0bits.ADON = 1

#define adc_read(channel) \
    ADCON0bits.CHS = channel; /* Asigna el canal del ADC */ \
    adc_reading() /* Función para retornar el valor del ADC*/ 

unsigned int adc_reading(){
    ADCON0bits.GO_DONE = 1; /* Inicia la conversión */ 
    while (ADCON0bits.GO_DONE == 1); /* Espera a que la conversión termine */
    return ((ADRESH << 8) | ADRESL); /* Devuelve el valor del ADC */
}
