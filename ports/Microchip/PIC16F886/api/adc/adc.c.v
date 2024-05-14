// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F886 port)
module adc

#define f_30ksps_1mhz	0	// VREF 3.0v
#define f_30ksps_4mhz	1	// VREF 3.0v 
#define f_18ksps_8mhz	2	// VREF full range
#define f_21ksps_10mhz	2	// VREF full range
#define f_24ksps_12mhz	2	// VREF 3.0v
#define f_30ksps_16mhz	2	// VREF 3.0v
#define f_34ksps_20mhz	2	// VREF 3.0v
#define f_18Ksps_irc	3	// sleep mode FOSC > 1Mhz