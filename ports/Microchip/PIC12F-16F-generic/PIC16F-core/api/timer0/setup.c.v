// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Timer0 functions for 16F family
module timer0

@[as_macro] const max_cycles_presc_1 = u32(1024) // 4 cycles * PRESCALER * 256
@[as_macro] const max_cycles_presc_2 = u32(2048)
@[as_macro] const max_cycles_presc_4 = u32(4096)
@[as_macro] const max_cycles_presc_8 = u32(8192)
@[as_macro] const max_cycles_presc_16 = u32(16384)
@[as_macro] const max_cycles_presc_32 = u32(32768)
@[as_macro] const max_cycles_presc_64 = u32(65536)
@[as_macro] const max_cycles_presc_128 = u32(131072)

@[as_macro] fn max_t_prescaler(max_cycles_presc u32) u32 {
	return u32(max_cycles_presc / u8(C._const_main__cpu_freq_mhz))
}

@[as_macro] const presc_1_shift = u8(2) // amount of bit shifts to obtain (4 * PRE)
@[as_macro] const presc_2_shift = u8(3)
@[as_macro] const presc_4_shift = u8(4)
@[as_macro] const presc_8_shift = u8(5)
@[as_macro] const presc_16_shift = u8(6)
@[as_macro] const presc_32_shift = u8(7)
@[as_macro] const presc_64_shift = u8(8)
@[as_macro] const presc_128_shift = u8(9)
@[as_macro] const presc_256_shift = u8(10)

@[as_macro] fn init_value(period u32, shift u8) u8 {
	return u8(256 - u16(period >> shift) * u16(C._const_main__cpu_freq_mhz))
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
@[as_macro] pub fn setup(period u32) {
	C.T0CS = 0
	if period <= max_t_prescaler(max_cycles_presc_1) {
		C.PSA = 1 // without prescaler
		timer0__initial = init_value(period, presc_1_shift)
	} else {
		C.PSA = 0
		C.OPTION_REG &= 0b11111000 // deletes 3 LSBs
		if period <= max_t_prescaler(max_cycles_presc_2) {
			C.OPTION_REG |= 0b000 // 2 prescaler
			timer0__initial = init_value(period, presc_2_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_4) {
			C.OPTION_REG |= 0b001 // 4 prescaler
			timer0__initial = init_value(period, presc_4_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_8) {
			C.OPTION_REG |= 0b010 // 8 prescaler
			timer0__initial = init_value(period, presc_8_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_16) {
			C.OPTION_REG |= 0b011 // 16 prescaler
			timer0__initial = init_value(period, presc_16_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_32) {
			C.OPTION_REG |= 0b100 // 32 prescaler
			timer0__initial = init_value(period, presc_32_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_64) {
			C.OPTION_REG |= 0b101 // 64 prescaler
			timer0__initial = init_value(period, presc_64_shift)
		} else if period <= max_t_prescaler(max_cycles_presc_128) {
			C.OPTION_REG |= 0b110 // 128 prescaler
			timer0__initial = init_value(period, presc_128_shift)
		} else {
			C.OPTION_REG |= 0b111 // 256 prescaler
			timer0__initial = init_value(period, presc_256_shift)
		}
	}
	C.TMR0 = u8(timer0__initial)
}

// setup configures the Timer0
// @[as_macro] // pub fn setup(period u16) {
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
