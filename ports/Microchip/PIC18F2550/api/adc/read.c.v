// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions  (PIC18F2550 port)

module adc

fn read(channel u8) int {
    ADCON0bits.CHS = channel      // Asigna el canal del ADC  
    adc__reading()                // Función para retornar el valor del ADC 
}