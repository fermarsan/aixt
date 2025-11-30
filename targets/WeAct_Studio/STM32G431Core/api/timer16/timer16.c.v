// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer16

#include "timer16.c"

@[as_macro] pub const tick  = C.TICK_FORMAT
@[as_macro] pub const ms    = C.MICROSEC_FORMAT   
@[as_macro] pub const hz    = C.HERTZ_FORMAT
@[as_macro] pub const pwm1  = C.TIMER_OUTPUT_COMPARE_PWM1


@[as_macro] pub const compare_ch1  = 1
@[as_macro] pub const compare_ch2  = 2
@[as_macro] pub const compare_ch3  = 3

fn C.TIMER16_SETOVERFLOW(value f32, format int)
fn C.TIMER16_ATTACHINTERRUPT(handler fn())
fn C.TIMER16_COMPARE_ATTACHINTERRUPT(channel int, handler fn()) 
fn C.TIMER16_RESUME() 
fn C.ptr_timer16_isr()
fn C.TIMER16_WRITE_PERCENT_CHANNEL(channel int, val int)
fn C.TIMER16_WRITE_PERCENT(val int)
fn C.TIMER16_SETMODE(channel int, mode int, pin int)

fn C.TIMER16_COMPARE_CHANNEL_ISR(channel int, handler fn()) fn()

@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER16_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER16_COMPARE_CHANNEL_ISR(ch, C.ptr_timer16_isr)
	)
}

@[as_macro]
pub fn irq_enable() {
	C.TIMER16_ATTACHINTERRUPT(C.ptr_timer16_isr)
}

@[as_macro]
pub fn write_percent(val int) {
    C.TIMER16_WRITE_PERCENT(val)
}

@[as_macro]
pub fn write_percent_channel(channel int, val int) {
    C.TIMER16_WRITE_PERCENT_CHANNEL(channel, val)
}

@[as_macro]
pub fn restart() {
	C.TIMER16_RESUME() 
}

@[as_macro]
pub fn setmode(channel int, mode int, pin int) {
	C.TIMER16_SETMODE(channel, mode, pin)
}

@[as_macro]
pub fn setup(value f32, format int) {
	C.TIMER16_SETOVERFLOW(value, format)
}