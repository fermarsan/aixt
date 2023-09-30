// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2023
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
#include <p24FJ128GA010.h>

#define adc_setup() \ 
    AD1CON1 = 0x00E0; \ 
    AD1CSSL = 0; \       
    AD1CON2 = 0; \       
    AD1CON3 = 0x1F02; \   
    AD1CON1bits.ADON = 1

#define adc_read(CHANNEL) \
({ \   
    AD1CHS = CHANNEL; \           
    AD1CON1bits.SAMP = 1; \       
    while (!AD1CON1bits.DONE); \  
    ADC1BUF0; \                   
})

// void ADC_setup() // setup function
// {
//     AD1CON1 = 0x00E0; // automatic conversion start after sampling
//     AD1CSSL = 0; // no scanning required
//     AD1CON2 = 0; // use MUXA, AVss and AVdd are used as Vref+/-
//     AD1CON3 = 0x1F02; // Tsamp = 32 x Tad; Tad=125ns
//     AD1CON1bits.ADON = 1; // turn on the ADC
// }

// int adc_read(int channel)    // read the converted value
// {
//     AD1CHS = channel;           // 1. select analog input channel
//     AD1CON1bits.SAMP = 1;       // 2. start sampling
//     while (!AD1CON1bits.DONE);  // 3. wait for the conversion to complete
//     return ADC1BUF0;            // 4. read the conversion result
// }