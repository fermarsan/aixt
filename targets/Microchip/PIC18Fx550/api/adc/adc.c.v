// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

module adc
#include <xc.h>

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)


fn read(channel u8) int {
    ADCON0bits.CHS = channel      // Asigna el canal del ADC  
    ADCON0bits.GO_DONE = 1             // Inicia la conversion
    for (ADCON0bits.GO_DONE == 1) {}   // Espera a que termine la conversion
    return ADRES   
}

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)


fn setup() {            
    ADCON1 = 0x00       /* Vref = VSS y GND, Configuracion de entradas analogicas */ 
    ADCON0 = 0x00       /* Configura el modulo ADC */
    ADCON2 = 0x97       /* Tiempo de adquisicion, Justificacion hacia la derecha */
    ADCON0bits.ADON = 1
    }