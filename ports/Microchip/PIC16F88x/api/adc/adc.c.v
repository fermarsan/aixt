// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

// ADC analog pins 
@[as_macro] pub const in0 	= 0b1111111111111110		
@[as_macro] pub const in1 	= 0b1111111111111101			
@[as_macro] pub const in2 	= 0b1111111111111011			
@[as_macro] pub const in3 	= 0b1111111111110111			
@[as_macro] pub const in4 	= 0b1111111111101111			
@[as_macro] pub const in5 	= 0b1111111111011111			
@[as_macro] pub const in6 	= 0b1111111110111111			
@[as_macro] pub const in7 	= 0b1111111101111111			
@[as_macro] pub const in8 	= 0b1111111011111111			
@[as_macro] pub const in9 	= 0b1111110111111111			
@[as_macro] pub const in10	= 0b1111101111111111
// @[as_macro] pub const in11	= 0b1111011111111111		
// @[as_macro] pub const in12	= 0b1110111111111111		
// @[as_macro] pub const in13	= 0b1101111111111111		
// @[as_macro] pub const in14	= 0b1011111111111111		
// @[as_macro] pub const in15	= 0b0111111111111111


// ADC frequency
@[as_macro] pub const f_30ksps_1mhz		= 0	// VREF 3.0v
@[as_macro] pub const f_30ksps_4mhz		= 1	// VREF 3.0v 
@[as_macro] pub const f_18ksps_8mhz		= 2	// VREF full range
@[as_macro] pub const f_21ksps_10mhz 	= 2	// VREF full range
@[as_macro] pub const f_24ksps_12mhz 	= 2	// VREF 3.0v
@[as_macro] pub const f_30ksps_16mhz 	= 2	// VREF 3.0v
@[as_macro] pub const f_34ksps_20mhz 	= 2	// VREF 3.0v
@[as_macro] pub const f_18ksps_irc		= 3	// sleep mode FOSC > 1Mhz

// ADC conversion bits
@[as_macro] pub const bits_8	= 0
@[as_macro] pub const bits_10	= 1

// ADC input channels

@[as_macro] pub const ch0 	= 0 		
@[as_macro] pub const ch1 	= 1 			
@[as_macro] pub const ch2 	= 2 			
@[as_macro] pub const ch3 	= 3 			
@[as_macro] pub const ch4 	= 4 			
@[as_macro] pub const ch5 	= 5 			
@[as_macro] pub const ch6 	= 6 			
@[as_macro] pub const ch7 	= 7 			
@[as_macro] pub const ch8 	= 8 			
@[as_macro] pub const ch9 	= 9 			
@[as_macro] pub const ch10	= 10		
// @[as_macro] pub const ch11	= 11	
// @[as_macro] pub const ch12	= 12	
// @[as_macro] pub const ch13	= 13	
// @[as_macro] pub const ch14	= 14	
// @[as_macro] pub const ch15	= 15