// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions
//              (PIC16F676 port)
module adc


// ADC analog pins (negated by join them with &&)
@[as_macro] pub const in0 	= u8(0b11111110)
@[as_macro] pub const in1 	= u8(0b11111101)	
@[as_macro] pub const in2 	= u8(0b11111011)	
@[as_macro] pub const in3 	= u8(0b11110111)	
@[as_macro] pub const in4 	= u8(0b11101111)	
@[as_macro] pub const in5 	= u8(0b11011111)	
@[as_macro] pub const in6 	= u8(0b10111111)	
@[as_macro] pub const in7 	= u8(0b01111111)	
@[as_macro] pub const all_analogs  = u8(0b00000000)
@[as_macro] pub const all_digitals = u8(0b11111111)

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
