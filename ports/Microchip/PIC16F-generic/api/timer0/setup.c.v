// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Timer0 functions for 16F family
module timer0

// setup configures the Timer0
@[as_macro]
pub fn setup(period u16) {
	timer0__prescaler = i8(7)
	timer0__initial = i8(-1)
	for (timer0__initial < 0 || timer0__initial > 127) && timer0__prescaler >= 0 {
		timer0__prescaler--
		timer0__initial = i8( 256 - (period*C._const_main__cpu_freq_mhz) / (4*(1 << (timer0__prescaler+1))) )
	}
	C.T0CS = 0	// internal clock
	if timer0__prescaler == -1 {
		C.PSA =  1 
	} else { 
		C.PSA =  0 	 
		C.OPTION_REG &= 0b11111000			// deletes 3 LSBs
		C.OPTION_REG |= timer0__prescaler	// loads 3 LSBs with prescaler
	}
	C.TMR0 = u8(timer0__initial)
}