// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#define adc_read(CHANNEL) ({ AD1CHS = CHANNEL; AD1CON1bits.SAMP = 1; while (!AD1CON1bits.DONE); ADC1BUF0; })

// int adc_read(int channel)    // read the converted value
// {
//     AD1CHS = channel;           // 1. select analog input channel
//     AD1CON1bits.SAMP = 1;       // 2. start sampling
//     while (!AD1CON1bits.DONE);  // 3. wait for the conversion to complete
//     return ADC1BUF0;            // 4. read the conversion result
// }