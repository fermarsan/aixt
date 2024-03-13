// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

module adc

fn setup() {            
    ADCON1 = 0x00       /* Vref = VSS y GND, Configuracion de entradas analogicas */ 
    ADCON0 = 0x00       /* Configura el modulo ADC */
    ADCON2 = 0x97       /* Tiempo de adquisicion, Justificacion hacia la derecha */
    ADCON0bits.ADON = 1
    }