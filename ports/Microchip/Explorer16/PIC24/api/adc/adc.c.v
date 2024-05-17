// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#include <p24FJ128GA010.h>

#define	adc__in0 	0b1111111111111110		// analog inputs
#define	adc__in1 	0b1111111111111101			
#define	adc__in2 	0b1111111111111011			
#define	adc__in3 	0b1111111111110111			
#define	adc__in4 	0b1111111111101111			
#define	adc__in5 	0b1111111111011111			
#define	adc__in6 	0b1111111110111111			
#define	adc__in7 	0b1111111101111111			
#define	adc__in8 	0b1111111011111111			
#define	adc__in9 	0b1111110111111111			
#define	adc__in10	0b1111101111111111		
#define	adc__in11	0b1111011111111111		
#define	adc__in12	0b1110111111111111		
#define	adc__in13	0b1101111111111111		
#define	adc__in14	0b1011111111111111		
#define	adc__in15	0b0111111111111111

#define pot		5	// Onboard potentiometer

fn C.init()
