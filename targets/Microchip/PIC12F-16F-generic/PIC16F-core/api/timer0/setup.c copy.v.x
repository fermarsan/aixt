// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Timer0 functions for 16F family
module timer0

@[as_macro]
fn init_value(period u32, shift u8) u8 {
	return u8(256 - u16(period >> shift) * u16(C._const_main__cpu_freq_mhz))
}

@[as_macro]
fn max_t_fosc(time u32) u32 {
	return u32(time / u8(C._const_main__cpu_freq_mhz))
}

// setup configures the period of the Timer0 in microseconds
// | fosc [Mhz] | max period |
// |------------|------------|
// | 4          | 65536      |
// | 8          | 32768      |
// | 10         | 26214      |
// | 12         | 21845      |
// | 16         | 16384      |
// | 20         | 13107      |
@[as_macro]
pub fn setup(period u32) {
	C.T0CS = 0
	if period <= max_t_fosc(1024) {
		C.PSA = 1 // without prescaler
		timer0__initial = init_value(period, 2)
	} else {
		C.PSA = 0
		C.OPTION_REG &= 0b11111000 // deletes 3 LSBs
		if period <= max_t_fosc(2048) {
			C.OPTION_REG |= 0b000 // 2 prescaler
			timer0__initial = init_value(period, 3)
		} else if period <= max_t_fosc(4096) {
			C.OPTION_REG |= 0b001 // 4 prescaler
			timer0__initial = init_value(period, 4)
		} else if period <= max_t_fosc(8192) {
			C.OPTION_REG |= 0b010 // 8 prescaler
			timer0__initial = init_value(period, 5)
		} else if period <= max_t_fosc(16384) {
			C.OPTION_REG |= 0b011 // 16 prescaler
			timer0__initial = init_value(period, 6)
		} else if period <= max_t_fosc(32768) {
			C.OPTION_REG |= 0b100 // 32 prescaler
			timer0__initial = init_value(period, 7)
		} else if period <= max_t_fosc(65536) {
			C.OPTION_REG |= 0b101 // 64 prescaler
			timer0__initial = init_value(period, 8)
		} else if period <= max_t_fosc(131072) {
			C.OPTION_REG |= 0b110 // 128 prescaler
			timer0__initial = init_value(period, 9)
		} else {
			C.OPTION_REG |= 0b111 // 256 prescaler
			timer0__initial = init_value(period, 10)
		}
	}
	C.TMR0 = u8(timer0__initial)
}

// setup configures the Timer0
// @[as_macro]
// pub fn setup(period u16) {
// 	timer0__prescaler = i8(7)
// 	timer0__initial = i8(-1)
// 	for (timer0__initial < 0 || timer0__initial > 127) && timer0__prescaler >= 0 {
// 		timer0__prescaler--
// 		timer0__initial = i8( 256 - (period*C._const_main__cpu_freq_mhz) / (4*(1 << (timer0__prescaler+1))) )
// 	}
// 	C.T0CS = 0	// internal clock
// 	if timer0__prescaler == -1 {
// 		C.PSA =  1
// 	} else {
// 		C.PSA =  0
// 		C.OPTION_REG &= 0b11111000			// deletes 3 LSBs
// 		C.OPTION_REG |= timer0__prescaler	// loads 3 LSBs with prescaler
// 	}
// 	C.TMR0 = u8(timer0__initial)
// }
