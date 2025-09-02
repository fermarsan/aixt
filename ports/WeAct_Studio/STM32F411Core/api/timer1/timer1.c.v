// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer1

#include "timer1.c"

TIM_TypeDef *inst = TIM1;
HardwareTimer *timer1 = new HardwareTimer(inst);

@[as_macro] pub const tick  = C.TICK_FORMAT
@[as_macro] pub const ms    = C.MICROSEC_FORMAT   
@[as_macro] pub const hz    = C.HERTZ_FORMAT
@[as_macro] pub const pwm1  = C.TIMER_OUTPUT_COMPARE_PWM1


@[as_macro] pub const compare_ch1  = 1
@[as_macro] pub const compare_ch2  = 2
@[as_macro] pub const compare_ch3  = 3

fn C.TIMER1_SETOVERFLOW(value f32, format int)
fn C.TIMER1_ATTACHINTERRUPT(handler fn())
fn C.TIMER1_COMPARE_ATTACHINTERRUPT(channel int, handler fn()) 
fn C.TIMER1_RESUME() 
fn C.ptr_timer1_isr()
fn C.TIMER1_WRITE_PERCENT_CHANNEL(channel int, val int)
fn C.TIMER1_WRITE_PERCENT(val int)
fn C.TIMER1_SETMODE(channel int, mode int, pin int)

fn C.TIMER1_COMPARE_CHANNEL_ISR(channel int, handler fn()) fn()

// setup configures the period of the Timer1 in microseconds
@[as_macro]
pub fn setup(value f32, format int) {
	C.TIMER1_SETOVERFLOW(value, format)
}

// irq_enable enables the Timer1 overflow interrupt
@[as_macro]
pub fn irq_enable() {
	C.TIMER1_ATTACHINTERRUPT(C.ptr_timer1_isr)
}

// compare_irq_enable enables the Timer1 compare interrupt
@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER1_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER1_COMPARE_CHANNEL_ISR(ch, C.ptr_timer1_isr)
	)
}

// write_percent writes a percentage value to the Timer1
@[as_macro]
pub fn write_percent(val int) {
    C.TIMER1_WRITE_PERCENT(val)
}

// write_percent_channel writes a percentage value to a specific channel of Timer1
@[as_macro]
pub fn write_percent_channel(channel int, val int) {
    C.TIMER1_WRITE_PERCENT_CHANNEL(channel, val)
}

// restart the Timer1
@[as_macro]
pub fn restart() {
	C.TIMER1_RESUME() 
}

// setmode sets the mode of a Timer1 channel
@[as_macro]
pub fn setmode(channel int, mode int, pin int) {
	C.TIMER1_SETMODE(channel, mode, pin)
}