// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: ADC setup (PIC16F886 port)
module adc

#define adc__setup(PINS, FAD)  AD1PCFG = PINS;  AD1CON3bits.ADCS = (uint8_t)(((FCY>>8) / (int)(FAD)>>4) - 1) 