// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
// Description: Builtin definitions (CY8CKIT-049-42XX)
//              
#include <stdint.h>
#include <stdbool.h>
#include "builtin.c"

fn C.INIT_INTERRUPTS()


@[as_macro] pub const led1 = C.led1
@[as_macro] pub const _led2 = C.led2
@[as_macro] pub const do0 = 3
@[as_macro] pub const do1 = 4
@[as_macro] pub const do2 = 5
@[as_macro] pub const do3 = 6
@[as_macro] pub const do4 = 7
@[as_macro] pub const do5 = 8
@[as_macro] pub const do6 = 9
@[as_macro] pub const do7 = 10
@[as_macro] pub const do8 = 11
@[as_macro] pub const do9 = 12
@[as_macro] pub const do10 = 13
@[as_macro] pub const sw1 =C.sw1
@[as_macro] pub const di0 = 20
@[as_macro] pub const di1 = 21
@[as_macro] pub const di2 = 22
@[as_macro] pub const di3 = 23
@[as_macro] pub const di4 = 24
@[as_macro] pub const di5 = 25
@[as_macro] pub const di6 = 26
@[as_macro] pub const di7 = 27
@[as_macro] pub const di8 = 28
@[as_macro] pub const di9 = 29
@[as_macro] pub const di10 = 30


pub fn init() {
    C.INIT_INTERRUPTS() 
}