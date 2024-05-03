// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#include <p24FJ128GA010.h>

#define	500ksps		500000
#define	250ksps		250000
#define	200ksps		200000
#define	125ksps		125000
#define	100ksps		100000
#define	 50ksps		50000
#define	 40ksps		40000
#define	 25ksps		25000
#define	 20ksps		20000

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

fn C.init()
