// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//	- Javier Leon
//	- Camilo Lucas
//	- Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: Builtin definitions
//              (CY8CKIT-145-40XX)

#include <stdint.h>
#include "builtin.c"

fn C.INIT_INTERRUPTS() 


@[as_macro] pub const led1 = 0
@[as_macro] pub const _led2 = 1
@[as_macro] pub const _led3 = 2
@[as_macro] pub const led4 = 3
@[as_macro] pub const led5 = 4
@[as_macro] pub const led6 = 5
@[as_macro] pub const led7 = 6
@[as_macro] pub const led8 = 7
@[as_macro] pub const led9 = 8
@[as_macro] pub const led10 = 9
@[as_macro] pub const led11 = 10
@[as_macro] pub const _led12 = 11
@[as_macro] pub const do0 = 12
@[as_macro] pub const do1 = 13
@[as_macro] pub const do2 = 14
@[as_macro] pub const pwm_1 = 15
@[as_macro] pub const pwm_2 = 16
@[as_macro] pub const pwm_3 = 17
@[as_macro] pub const _sw1 = 18
@[as_macro] pub const sw2 = 19
@[as_macro] pub const di0 = 20
@[as_macro] pub const di1 = 21
@[as_macro] pub const di2 = 22
@[as_macro] pub const btn0 = 23
@[as_macro] pub const btn1 = 24
@[as_macro] pub const btn2 = 25
@[as_macro] pub const sld0 = 26
@[as_macro] pub const sld1 = 27
@[as_macro] pub const sld2 = 28
@[as_macro] pub const sld3 = 29
@[as_macro] pub const sld4 = 30

// enum __pin_names {
// led1,
// _led2,
// _led3,
// led4,
// led5,
// led6,
// led7,
// led8,
// led9,
// led10,
// led11,
// _led12,
// do0,
// do1,
// do2,
// pwm_1,
// pwm_2,
// pwm_3,
// _sw1,
// sw2,
// di0,
// di1,
// di2,
// btn0,
// btn1,
// btn2,
// sld0,
// sld1,
// sld2,
// sld3,
// sld4,
// };  

pub fn init() {
    C.INIT_INTERRUPTS() 
}