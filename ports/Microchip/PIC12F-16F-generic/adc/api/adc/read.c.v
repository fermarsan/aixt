// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

@[inline]
pub fn read(channel u8) u16 {    
    C.ADCON0bits.CHS = channel			/* assign the ADC channel */    
    C.ADCON0bits.GO_DONE = 1     		/* start conversion */  
    for C.ADCON0bits.GO_DONE == 1 {}	/* wait for the end of conversion */    
    return u16((C.ADRESH << 8) | C.ADRESL)	/* return the ADC value */  
}