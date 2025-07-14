// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: ADC management functions PIC16F676
module adc

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