// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2025
// License: MIT
//
// // Description: pwm functions (CY8CKIT-145-40XX)


module pwm   

// #include "pwm.c"

// fn C.PWM_WRITE(name any, value any)
fn C.pwm_0_WriteCompare(val any)
fn C.pwm_1_WriteCompare(val any)
fn C.pwm_2_WriteCompare(val any)

@[as_macro] pub const ch0 = 17
@[as_macro] pub const ch1 = 15
@[as_macro] pub const ch2 = 16


