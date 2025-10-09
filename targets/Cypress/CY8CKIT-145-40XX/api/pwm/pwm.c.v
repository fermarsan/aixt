// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pwm functions (CY8CKIT-145-40XX)


module pwm   

fn C.pwm1_Start()
fn C.pwm2_Start()
fn C.pwm0_Start()
fn C.clock_Start()// #include "pwm.c"

// fn C.PWM_WRITE(name any, value any)
fn C.pwm0_WriteCompare(val any)
fn C.pwm1_WriteCompare(val any)
fn C.pwm2_WriteCompare(val any)

@[as_macro] pub const ch0 = 17
@[as_macro] pub const ch1 = 15
@[as_macro] pub const ch2 = 16


fn init() {
	C.pwm1_Start()
	C.pwm2_Start()
	C.pwm0_Start()
	C.clock_Start()
}



