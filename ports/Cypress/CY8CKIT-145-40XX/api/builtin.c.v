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
#include <stdbool.h>
#include "builtin.c"

fn C.INIT_INTERRUPTS() 


@[as_macro] pub const led_1 = C.led1
@[as_macro] pub const led_4 = C.led4
@[as_macro] pub const led_5 = C.led5
@[as_macro] pub const led_6 = C.led6
@[as_macro] pub const led_7 = C.led7
@[as_macro] pub const led_8 = C.led8
@[as_macro] pub const led_9 = C.led9
@[as_macro] pub const led_10 =C.led10
@[as_macro] pub const led_11 =C.led11
@[as_macro] pub const do0 = 12
@[as_macro] pub const do1 = 13
@[as_macro] pub const do2 = 14
@[as_macro] pub const pwm_1 = 15
@[as_macro] pub const pwm_2 = 16
@[as_macro] pub const pwm_0 = 17
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
// led_1,
//led _led_2,
//led _led_3,
//led led_4,
//led led_5,
//led led_6,
//led led_7,
//led led_8,
//led led_9,
//led led_10,
//led led_11,
//led led_11,
//led _led_12,
//led do0,
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