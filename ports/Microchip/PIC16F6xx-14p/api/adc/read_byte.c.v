// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

@[as_macro]
pub fn read_byte(channel u8) u8 {    
    C.ADCON0bits_CHS = channel  	    // select the ADC channel     
    C.GO_DONE = 1     	    // start conversion   
    for C.GO_DONE == 1 {}	// wait for the end of conversion     
    return u8(C.ADRESH)     // return the ADC value (8 bits)   
}