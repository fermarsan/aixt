// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Exp16-PIC24 port)
module adc

#include <p24FJ128GA010.h>

// ADC analog pins 
#define	adc.in0 	0b1111111111111110		
#define	adc.in1 	0b1111111111111101			
#define	adc.in2 	0b1111111111111011			
#define	adc.in3 	0b1111111111110111			
#define	adc.in4 	0b1111111111101111			
#define	adc.in5 	0b1111111111011111			
#define	adc.in6 	0b1111111110111111			
#define	adc.in7 	0b1111111101111111			
#define	adc.in8 	0b1111111011111111			
#define	adc.in9 	0b1111110111111111			
#define	adc.in10	0b1111101111111111		
#define	adc.in11	0b1111011111111111		
#define	adc.in12	0b1110111111111111		
#define	adc.in13	0b1101111111111111		
#define	adc.in14	0b1011111111111111		
#define	adc.in15	0b0111111111111111

// ADC input channels
#define	adc.ch0 	0 		
#define	adc.ch1 	1 			
#define	adc.ch2 	2 			
#define	adc.ch3 	3 			
#define	adc.ch4 	4 			
#define	adc.ch5 	5 			
#define	adc.ch6 	6 			
#define	adc.ch7 	7 			
#define	adc.ch8 	8 			
#define	adc.ch9 	9 			
#define	adc.ch10	10		
#define	adc.ch11	11		
#define	adc.ch12	12		
#define	adc.ch13	13		
#define	adc.ch14	14		
#define	adc.ch15	15

// Onboard potentiometer
#define pot		5	

fn C.init()

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Exp16-PIC24 port)


#include <libpic30.h>

fn C.read(channel u8) u16 

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// Description: ADC setup (Exp16-PIC24 port)


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