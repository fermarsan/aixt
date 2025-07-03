// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: ADC management functions PIC16F676
module adc

@[as_macro]
pub fn setup(pins u8, nbits u8) {
	// ---------- Select the analog pins ----------
    C.ANSEL = u8(~pins)
	// ---------- Set the pins as inputs ----------
	C.PORTA &= 0b111_0_1_000					// clean RA0-RA2 and RA4
	C.PORTA |= ~(pins | 0b11111_000)			// adc.in0-adc.in2 --> RA0-RA2		
	C.PORTA |= ~((pins | 0b1111_0_111) << 1)	// adc.in3 --> RA4
	C.PORTC &= 0b1111_0000						// clean RC0-RC3		
	C.PORTC |= ~((pins | 0b0000_1111) >> 4)		// adc.in4-adc.in7 --> RC0-RC3	
	// ---------- Set the ADC frequency ----------		
	for i in 0..6 {	// matching the proper division for Fosc
		if ((64 >> i)*1000) / C._const_main__cpu_freq_mhz >= 1600 &&
		   ((64 >> i)*1000) / C._const_main__cpu_freq_mhz <= 6400 {
			match i {
				0	{ C.ADCON1 = 0b0_110_0000 }		// Fosc/64
				1	{ C.ADCON1 = 0b0_010_0000 }		// Fosc/32
				2	{ C.ADCON1 = 0b0_101_0000 }		// Fosc/16
				3	{ C.ADCON1 = 0b0_001_0000 }		// Fosc/8 
				4	{ C.ADCON1 = 0b0_100_0000 }		// Fosc/4 
				5	{ C.ADCON1 = 0b0_000_0000 }		// Fosc/2 
				else { C.ADCON1 = 0b0_011_0000 }	// F_RC
			}
			break
		}
	}
	// ---------- Turn on the ADC ----------
    C.ADFM = nbits
    C.ADON = 1
}