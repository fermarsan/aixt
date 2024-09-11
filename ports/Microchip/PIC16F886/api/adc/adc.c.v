// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F886 port)
module adc

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
// #define	adc.in11	0b1111011111111111		
// #define	adc.in12	0b1110111111111111		
// #define	adc.in13	0b1101111111111111		
// #define	adc.in14	0b1011111111111111		
// #define	adc.in15	0b0111111111111111

// ADC frequency
#define adc.f_30ksps_1mhz	0	// VREF 3.0v
#define adc.f_30ksps_4mhz	1	// VREF 3.0v 
#define adc.f_18ksps_8mhz	2	// VREF full range
#define adc.f_21ksps_10mhz	2	// VREF full range
#define adc.f_24ksps_12mhz	2	// VREF 3.0v
#define adc.f_30ksps_16mhz	2	// VREF 3.0v
#define adc.f_34ksps_20mhz	2	// VREF 3.0v
#define adc.f_18ksps_irc	3	// sleep mode FOSC > 1Mhz

// ADC conversion bits
#define	adc.bits_8		0
#define	adc.bits_10	1

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
// #define	adc.ch11	11		
// #define	adc.ch12	12		
// #define	adc.ch13	13		
// #define	adc.ch14	14		
// #define	adc.ch15	15
