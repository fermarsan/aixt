// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: ADC management functions for PIC16F family
module adc

// ADC analog pins (negated by join them with &&)
@[as_macro] pub const in0 	= u16(0b1111111111111110)		
@[as_macro] pub const in1 	= u16(0b1111111111111101)			
@[as_macro] pub const in2 	= u16(0b1111111111111011)			
@[as_macro] pub const in3 	= u16(0b1111111111110111)			
@[as_macro] pub const in4 	= u16(0b1111111111101111)			
@[as_macro] pub const in5 	= u16(0b1111111111011111)			
@[as_macro] pub const in6 	= u16(0b1111111110111111)			
@[as_macro] pub const in7 	= u16(0b1111111101111111)			
@[as_macro] pub const in8 	= u16(0b1111111011111111)			
@[as_macro] pub const in9 	= u16(0b1111110111111111)			
@[as_macro] pub const in10	= u16(0b1111101111111111)
@[as_macro] pub const in11	= u16(0b1111011111111111)		
@[as_macro] pub const in12	= u16(0b1110111111111111)		
@[as_macro] pub const in13	= u16(0b1101111111111111)		
@[as_macro] pub const in14	= u16(0b1011111111111111)		
@[as_macro] pub const in15	= u16(0b0111111111111111)
@[as_macro] pub const all_analogs  = u16(0b0000000000000000)
@[as_macro] pub const all_digitals = u16(0b1111111111111111)

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
@[as_macro] pub const ch11	= 11	
@[as_macro] pub const ch12	= 12	
@[as_macro] pub const ch13	= 13	
@[as_macro] pub const ch14	= 14	
@[as_macro] pub const ch15	= 15


// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: ADC analog pin setup for PIC16F88x family


@[as_macro]
fn set_as_analog(pins any) {
	C.ANSEL = u8(~pins)
    C.ANSELH = u8(~pins>>8)
}