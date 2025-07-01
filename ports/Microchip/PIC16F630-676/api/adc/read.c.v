// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

@[as_macro]
pub fn read(channel u8) u16 {    
    C.CHS = channel			// assign the ADC channel     
    C.GO_DONE = 1     		// start conversion   
    for C.GO_DONE == 1 {}	// wait for the end of conversion     
    return u16((C.ADRESH << 8) | C.ADRESL)	// return the ADC value (16 bits)
}