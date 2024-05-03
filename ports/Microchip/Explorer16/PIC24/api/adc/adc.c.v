// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#include <p24FJ128GA010.h>


#define	16mhz	16000000UL
#define	8mhz	8000000UL
#define	4mhz	4000000UL
#define	3_2mhz	3200000UL
#define	2mhz	2000000UL
#define	1_6mhz	1600000UL
#define	1mhz	1000000UL
#define	800khz	800000UL
#define	640khz	640000UL
#define	500khz	500000UL
#define	400khz	400000UL
#define	320khz	320000UL
#define	250khz	250000UL

enum analog_channels {
	ch0 = 0			
	ch1			
	ch2			
	ch3			
	ch4			
	ch5			
	ch6			
	ch7			
	ch8			
	ch9			
	ch10		
	ch11		
	ch12		
	ch13		
	ch14		
	ch15
}

#define pot		5	// Onboard potentiometer

#define	an0 	0x1111111111111110		// analog pins
#define	an1 	0x1111111111111101			
#define	an2 	0x1111111111111011			
#define	an3 	0x1111111111110111			
#define	an4 	0x1111111111101111			
#define	an5 	0x1111111111011111			
#define	an6 	0x1111111110111111			
#define	an7 	0x1111111101111111			
#define	an8 	0x1111111011111111			
#define	an9 	0x1111110111111111			
#define	an10	0x1111101111111111		
#define	an11	0x1111011111111111		
#define	an12	0x1110111111111111		
#define	an13	0x1101111111111111		
#define	an14	0x1011111111111111		
#define	an15	0x0111111111111111

fn C.init()
