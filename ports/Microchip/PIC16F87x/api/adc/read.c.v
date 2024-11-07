// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)

module adc

[inline]
fn read(channel u16) u16 {
    C.ADCON0bits.CHS = channel  // Assigns the ADC channel
    C.ADCON0bits.GO_DONE = 1    // Starts conversion
    for C.ADCON0bits.GO_DONE == 1 {}    // Waits for conversion to end
    return (C.ADRESH << 8) | C.ADRESL   // Return the ADC value
}

