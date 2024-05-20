// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F886 port)
module adc

#define	adc__in0 	0b1111111111111110		// analog pins
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
// #define	adc__in11	0b1111011111111111		
// #define	adc__in12	0b1110111111111111		
// #define	adc__in13	0b1101111111111111		
// #define	adc__in14	0b1011111111111111		
// #define	adc__in15	0b0111111111111111

// ADC frequency
#define adc__f_30ksps_1mhz	0	// VREF 3.0v
#define adc__f_30ksps_4mhz	1	// VREF 3.0v 
#define adc__f_18ksps_8mhz	2	// VREF full range
#define adc__f_21ksps_10mhz	2	// VREF full range
#define adc__f_24ksps_12mhz	2	// VREF 3.0v
#define adc__f_30ksps_16mhz	2	// VREF 3.0v
#define adc__f_34ksps_20mhz	2	// VREF 3.0v
#define adc__f_18ksps_irc	3	// sleep mode FOSC > 1Mhz

// ADC conversion bits
#define	adc__bits_8		0
#define	adc__bits_10	1