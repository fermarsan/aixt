// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions
//              (PIC16F676 port)
module adc


#include "adc.c"

// ADC analog pins (are negated by join them with &&)
@[as_macro] pub const in0 	= u8(0b11111110)
@[as_macro] pub const in1 	= u8(0b11111101)	
@[as_macro] pub const in2 	= u8(0b11111011)	
@[as_macro] pub const in3 	= u8(0b11110111)	
@[as_macro] pub const in4 	= u8(0b11101111)	
@[as_macro] pub const in5 	= u8(0b11011111)	
@[as_macro] pub const in6 	= u8(0b10111111)	
@[as_macro] pub const in7 	= u8(0b01111111)	
@[as_macro] pub const all_analogs  = u8(0b00000000)
@[as_macro] pub const all_digitals = u8(0b11111111)

// ADC conversion bits
@[as_macro] pub const bits_8	= 0
@[as_macro] pub const bits_10	= 1

// ADC input channels
@[as_macro] pub const ch0 	= 0
@[as_macro] pub const ch1 	= 1
@[as_macro] pub const ch2 	= 2
@[as_macro] pub const ch3 	= 3
@[as_macro] pub const ch4 	= 4
@[as_macro] pub const ch5 	= 5
@[as_macro] pub const ch6 	= 6
@[as_macro] pub const ch7 	= 7

// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)

@[inline]
pub fn read_byte(channel u8) u8 {    
    C.ADCON0_CHS  = channel  	    // select the ADC channel     
    C.GO_DONE = 1     	    // start conversion   
    for C.GO_DONE == 1 {}	// wait for the end of conversion     
    return u8(C.ADRESH)     // return the ADC value (8 bits)   
}

// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)

@[inline]
pub fn read(channel u8) u16 {    
    C.ADCON0_CHS  = channel // assign the ADC channel     
    C.GO_DONE = 1     		// start conversion   
    for C.GO_DONE == 1 {}	// wait for the end of conversion     
    return u16((C.ADRESH << 8) | C.ADRESL)	// return the ADC value (16 bits)
}

// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: ADC management functions PIC16F676


// setup function configures de analog pins, the number of bits and the frequency
// of the ADC. 
@[as_macro]
pub fn setup(pins u8, nbits u8) {
	// ---------- Select the analog pins ----------
    C.ANSEL = u8(~pins)
	// ---------- Set the analog pins as inputs ----------
	C.TRISA &= 0b111_0_1_000					// clean RA0-RA2 and RA4
	C.TRISA |= ~(pins | 0b11111_000)			// adc.in0-adc.in2 --> RA0-RA2		
	C.TRISA |= ~((pins | 0b1111_0_111) << 1)	// adc.in3 --> RA4
	C.TRISC &= 0b1111_0000						// clean RC0-RC3		
	C.TRISC |= ~((pins | 0b0000_1111) >> 4)		// adc.in4-adc.in7 --> RC0-RC3	
	// ---------- Set the ADC frequency ----------
	C.ADCON1 = if C._const_main__cpu_freq_mhz >= 12 	{ 0b0_110_0000 }	// Fosc/64
			   else if C._const_main__cpu_freq_mhz >= 6	{ 0b0_010_0000 }	// Fosc/32
			   else if C._const_main__cpu_freq_mhz >= 3	{ 0b0_101_0000 }	// Fosc/16
			   else if C._const_main__cpu_freq_mhz >= 2	{ 0b0_001_0000 }	// Fosc/8 
			   else if C._const_main__cpu_freq_mhz >= 1	{ 0b0_100_0000 }	// Fosc/4 
			   else										{ 0b0_000_0000 }	// Fosc/2 
	// ---------- Turn on the ADC ----------
    C.ADFM = nbits
    C.ADON = 1	// C.ADCON0 |= 0b0000_0001	
}