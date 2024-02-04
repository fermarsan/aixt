// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

#include <xc.h>

#define adc_setup() \
    ADCON1 = 0x00; /* Vref = VSS y GND, Configuracion de entradas analogicas */ \
    ADCON0 = 0x00; /* Configura el modulo ADC */\
    ADCON2 = 0x97; /* Tiempo de adquisicion, Justificacion hacia la derecha */\
    ADCON0bits.ADON = 1

#define adc_read(channel) \
    ADCON0bits.CHS = channel; /* Asigna el canal del ADC */ \
    adc_reading()             /* Función para retornar el valor del ADC*/ 

unsigned int adc_reading(){
        ADCON0bits.GO_DONE = 1;             // Inicia la conversion
        while(ADCON0bits.GO_DONE == 1);     // Espera a que termine la conversion
        return ((ADRESH << 8) + ADRESL);
    }
