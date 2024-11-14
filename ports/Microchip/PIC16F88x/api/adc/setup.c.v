// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

@[as_macro]
pub fn setup(pins u16, fad u8, nbits u8) {
    /* analog pins setup */
    C.ANSEL = u8(~pins)
    C.ANSELH = u8(~pins>>8)
    /* ADC setup */
    C.ADCON1 = 0b00000000		/*VSS, VDD*/
    C.ADCON1bits.ADFM = nbits
    C.ADCON0bits.ADCS = fad
    C.ADCON0bits.ADON = 1
}