// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC setup (Explorer16-PIC24 port)
module adc

// setup receive the pins to be configured as analog and the sampling and converting frequency
// FREQ: sampling frequency (samples per second "sps")
// PINS: pins to be configured as analog inputs
// 

#define adc__setup(PINS, FREQ) AD1PCFG = PINS; AD1CON3bits.ADCS = (uint8_t)(((FCY>>4) / freq) - 1) 


