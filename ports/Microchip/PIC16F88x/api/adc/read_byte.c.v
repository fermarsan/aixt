// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

@[as_macro]
pub fn read_byte(channel u8) u8 {    
    C.ADCON0bits.CHS = channel  	    /* assign the ADC channel */    
    C.ADCON0bits.GO_DONE = 1     	    /* start conversion */  
    for C.ADCON0bits.GO_DONE == 1 {}	/* wait for the end of conversion */    
    return C.ADRESH              		/* return the ADC value (8 bits) */  
}