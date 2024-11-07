// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F88x port)
module adc

// ADC analog pins 
enum ADC__names as u16 {
	in0 	= 0b1111111111111110		
	in1 	= 0b1111111111111101			
	in2 	= 0b1111111111111011			
	in3 	= 0b1111111111110111			
	in4 	= 0b1111111111101111			
	in5 	= 0b1111111111011111			
	in6 	= 0b1111111110111111			
	in7 	= 0b1111111101111111			
	in8 	= 0b1111111011111111			
	in9 	= 0b1111110111111111			
	in10	= 0b1111101111111111
	// in11	= 0b1111011111111111		
	// in12	= 0b1110111111111111		
	// in13	= 0b1101111111111111		
	// in14	= 0b1011111111111111		
	// in15	= 0b0111111111111111
}		


// ADC frequency
enum ADC__frequencies as u8 {
	f_30ksps_1mhz	= 0	// VREF 3.0v
	f_30ksps_4mhz	= 1	// VREF 3.0v 
	f_18ksps_8mhz	= 2	// VREF full range
	f_21ksps_10mhz 	= 2	// VREF full range
	f_24ksps_12mhz 	= 2	// VREF 3.0v
	f_30ksps_16mhz 	= 2	// VREF 3.0v
	f_34ksps_20mhz 	= 2	// VREF 3.0v
	f_18ksps_irc	= 3	// sleep mode FOSC > 1Mhz
}

// ADC conversion bits
enum ADC__bits as u8 {
	bits_8		= 0
	bits_10		= 1
}

// ADC input channels
enum ADC_channels as u8 {
	ch0 	= 0 		
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
	// ch11		
	// ch12		
	// ch13		
	// ch14		
	// ch15
}