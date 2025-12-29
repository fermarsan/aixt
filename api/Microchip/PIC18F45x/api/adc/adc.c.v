// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// ADC
//              (PIC18F452)
module adc
#include <xc.h>

// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// adc.read
//              (PIC18F452)

fn read(channel u8) int { 
    ADCON0bits.CHS = channel /* Asigna el canal del ADC */ 
    ADCON0bits.GO_DONE = 1             // Inicia la conversion
    for (ADCON0bits.GO_DONE == 1)  {}   // Espera a que termine la conversion
    return ADRES
}

// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// ADC SETUP
//              (PIC18F452)

fn setup() {
    ADCON1 = 0xC0 /* Ajusta todos los canales como analogicos */ 
    ADCON0 = 0xC0 /* Ajusta todos las entradas como analogicos */
    ADCON0bits.ADON = 1
    }