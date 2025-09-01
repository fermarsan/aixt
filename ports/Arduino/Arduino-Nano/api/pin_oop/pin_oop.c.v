// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions Arduino devices
module pin

// pin names 
@[as_macro] pub const d0 = 0 
@[as_macro] pub const d1 = 1
@[as_macro] pub const d2 = 2
@[as_macro] pub const d3 = 3
@[as_macro] pub const d4 = 4
@[as_macro] pub const d5 = 5
@[as_macro] pub const d6 = 6
@[as_macro] pub const d7 = 7
@[as_macro] pub const d8 = 8
@[as_macro] pub const d9 = 9
@[as_macro] pub const d10 = 10
@[as_macro] pub const d11 = 11
@[as_macro] pub const d12 = 12
@[as_macro] pub const d13 = 13
@[as_macro] pub const d14 = 14
@[as_macro] pub const d15 = 15
@[as_macro] pub const d16 = 16
@[as_macro] pub const d17 = 17
@[as_macro] pub const d18 = 18
@[as_macro] pub const d19 = 19
@[as_macro] pub const d20 = 20
@[as_macro] pub const d21 = 21

// pin mode
@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

// builtin LED
pub const led0 = new(pin.d13, pin.input)