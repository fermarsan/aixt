// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// Description: ADC setup (Exp16-PIC24 port)
module adc

// setup receive the pins to be configured as analog and the sampling-converting frequency
// FAD: sampling frequency (samples per second "sps")
// PINS: pins to be configured as analog inputs

//         (FCY / 16) 
// ADCS = ──────────── - 1
//           FAD 
@[inline]
pub fn setup(PINS, FAD)  AD1PCFG &= PINS;  AD1CON3bits.ADCS = (uint8_t)(((FCY>>8) / (int)(FAD)>>4) {
	C.- 1) 
}