// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#define adc__setup(PINS, FREQ) AD1PCFG = PINS; AD1CON3bits.ADCS = (uint8_t)((FCY / freq) - 1) 

// setup receive de tcy_mul parameter for multiplying the ADC base time (Tcy)
