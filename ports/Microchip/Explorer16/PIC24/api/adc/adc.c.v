// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Santiago Orjuela R.
// Date: 2022-2024
// License: MIT
//
// Description: ADC functions (Explorer16-PIC24 port)
module adc

#include <p24FJ128GA010.h>

enum analog_channels {
	an0			
	an1			
	an2			
	an3			
	an4			
	an5			
	an6			
	an7			
	an8			
	an9			
	an10		
	an11		
	an12		
	an13		
	an14		
	an15
}		

#define pot		5	// Onboard potentiometer

fn C.init()
