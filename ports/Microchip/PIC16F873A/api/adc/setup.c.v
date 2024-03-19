// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F873A port)

module adc

#define adc__setup()  ADCON1 = 0b10000000;  ADCON0 = 0b11001000;  ADCON0bits.ADON = 1;





/*#define adc__setup() \
    ADCON1 = 0b10000000 /* Ajusta todos los canales como analogicos */ \
    ADCON0 = 0b11001000 /* Ajusta todos las entradas como analogicos */\
    ADCON0bits.ADON = 1
*/
