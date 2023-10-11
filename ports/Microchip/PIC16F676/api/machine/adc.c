
// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: ADC management functions
//              (PIC16F676 port)

#include <xc.h>


#define adc_setup() \
    ANSEL = 0b00000100; /* Configura el pin AN1 como entrada analógica */ \
    ADCON0 = 0b10000000; /* Habilita el ADC y selecciona AN1 como entrada */ \
    ADCON1 = 0b00110000; /* Ajusta la referencia de voltaje */\
    ADCON0bits.ADON = 1;

#define adc_read(CHANNEL) \
    ADCON0bits.CHS = CHANNEL; /* Asigna el canal del ADC */ \
    ADCON0bits.GO_DONE = 1; /* Inicia la conversión */ \
    while (ADCON0bits.GO_DONE == 1); /* Espera a que la conversión termine */ \
    adc_result = ((ADRESH << 8) | ADRESL); /* Devuelve el valor del ADC */\
    adc_result /* Devuelve el valor del ADC a la variable asignada*/