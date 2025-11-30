// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC18F452)
module pin

#include <xc.h>

@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

