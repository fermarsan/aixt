// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F676 port)

module adc

#define adc__setup()  ANSEL = 0b00000010;  ADCON0 = 0b10000000;  ADCON1 = 0b00110000;  ADCON0bits.ADON = 1     





/*
#define adc__setup() \
    ANSEL = 0b00000100  /* Configura el pin AN1 como entrada analógica */ \
    ADCON0 = 0b10000000 /* Habilita el ADC y selecciona AN1 como entrada */ \
    ADCON1 = 0b00110000 /* Ajusta la referencia de voltaje */\
    ADCON0bits.ADON = 1 /* Enciende en conversor ADC */
*/