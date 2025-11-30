// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Timer0 functions for 12F family
module timer0

#define TIMER0_IRQ_IN_USE

__global (
	timer0__initial = u8(0)
)

// @[as_macro] pub const no_pre  = u8(255)
// @[as_macro] pub const pre_2   = u8(0b000)
// @[as_macro] pub const pre_4   = u8(0b001)
// @[as_macro] pub const pre_8   = u8(0b010)
// @[as_macro] pub const pre_16  = u8(0b011)
// @[as_macro] pub const pre_32  = u8(0b100)
// @[as_macro] pub const pre_64  = u8(0b101)
// @[as_macro] pub const pre_128 = u8(0b110)
// @[as_macro] pub const pre_256 = u8(0b111)

// irq_disable disables the external interrupt
@[as_macro]
pub fn irq_disable() {
	C.T0IE = 0
}

// irq_enable enables the Timer0 overflow interrupt
@[as_macro]
pub fn irq_enable() {
	C.GIE = 1
	C.T0IE = 1
}

// read reads the current value of Timer0
@[as_macro]
pub fn read() u8 {
	return u8(C.TMR0)
}

// restart the Timer0 with the predefined starting value
@[as_macro]
pub fn restart() {
	C.TMR0 = u8(timer0__initial)
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
		C.PSA =  1	// without prescaler
		timer0__initial = timer0.init_value(period, 2)
	} else { 
		C.PSA =  0 	 
		C.OPTION_REG &= 0b11111000			// deletes 3 LSBs
		if period <= max_t_fosc(2048) {
			C.OPTION_REG |= 0b000	// 2 prescaler
			timer0__initial = timer0.init_value(period, 3)
		} else if period <= max_t_fosc(4096) {
			C.OPTION_REG |= 0b001	// 4 prescaler
			timer0__initial = timer0.init_value(period, 4)
		} else if period <= max_t_fosc(8192) {
			C.OPTION_REG |= 0b010	// 8 prescaler
			timer0__initial = timer0.init_value(period, 5)
		} else if period <= max_t_fosc(16384) {
			C.OPTION_REG |= 0b011	// 16 prescaler
			timer0__initial = timer0.init_value(period, 6)
		} else if period <= max_t_fosc(32768) {
			C.OPTION_REG |= 0b100	// 32 prescaler
			timer0__initial = timer0.init_value(period, 7)
		} else if period <= max_t_fosc(65536) {
			C.OPTION_REG |= 0b101	// 64 prescaler
			timer0__initial = timer0.init_value(period, 8)
		} else if period <= max_t_fosc(131072) {
			C.OPTION_REG |= 0b110	// 128 prescaler
			timer0__initial = timer0.init_value(period, 9)
		} else {
			C.OPTION_REG |= 0b111	// 256 prescaler
			timer0__initial = timer0.init_value(period, 10)
		}
	}
	C.TMR0 = u8(timer0__initial)
}

@[as_macro]
fn init_value(period u32, shift u8) u8 {
	return u8(256 - u16(period>>shift)*u16(C._const_main__cpu_freq_mhz))
}

@[as_macro]
fn max_t_fosc(time u32) u32{
	return u32(time / u8(C._const_main__cpu_freq_mhz))
}
