// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: 
//  - Daniel Polo 
//  - Edwin Barrera
//  - Fernando M. Santa 
//  - Javier Leon 
//  - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// Description: Builtin definitions (CY8CKIT-145-40XX)
//              

#include <stdint.h>
#include <stdbool.h>

#include "builtin.c"

fn C.INIT_INTERRUPTS() 


@[as_macro] pub const led1 =  C.led1
@[as_macro] pub const led4 =  C.led4
@[as_macro] pub const led5 =  C.led5
@[as_macro] pub const led6 =  C.led6
@[as_macro] pub const led7 =  C.led7
@[as_macro] pub const led8 =  C.led8
@[as_macro] pub const led9 =  C.led9
@[as_macro] pub const led10 = C.led10
@[as_macro] pub const led11 = C.led11
@[as_macro] pub const do0 = 12
@[as_macro] pub const do1 = 13
@[as_macro] pub const do2 = 14
@[as_macro] pub const sw2 = C.sw2
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
//led _led2,
//led _led3,
//led led4,
//led led5,
//led led6,
//led led7,
//led led8,
//led led9,
//led led10,
//led led11,
//led led11,
//led _led12,
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