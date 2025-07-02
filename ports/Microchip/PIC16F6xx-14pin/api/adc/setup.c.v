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
    C.ANSEL = ~u8(pins)
	// ---------- Set the ADC frequency ----------		
	for i in 0..6 {	// matching the proper division for Fosc
		if ((64 >> i)*1000) / C._const_main__cpu_freq_mhz >= 1600 &&
		   ((64 >> i)*1000) / C._const_main__cpu_freq_mhz <= 6400 {
			C.ADCON1 = match 64 >> i {
				64   { 0b0_110_0000 }
				32   { 0b0_010_0000 }
				16   { 0b0_101_0000 }
				8    { 0b0_001_0000 }
				4    { 0b0_100_0000 }
				2    { 0b0_000_0000 }
				else { 0b0_011_0000 }	// F_RC
			}
			break
		}
	}
	// ---------- Turn on the ADC ----------
    C.ADFM = nbits
    C.ADON = 1
}