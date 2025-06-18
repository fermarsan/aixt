// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer1

#include "timer1.c"

@[as_macro] pub const tick  = C.TICK_FORMAT
@[as_macro] pub const ms    = C.MICROSEC_FORMAT   
@[as_macro] pub const hz    = C.HERTZ_FORMAT

fn C.TIMER1_SETOVERFLOW(value int, format int)
fn C.TIMER1_ATTACHINTERRUPT(handler fn())
fn C.TIMER1_RESUME() 
fn C.ptr_timer1_isr()
