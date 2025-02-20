// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: External interrupts management functions for 16F family
module ext

#include "ext.c"

@[as_macro] pub const rising  = C.RISING  
@[as_macro] pub const falling = C.FALLING  
@[as_macro] pub const change = 	C.CHANGE 	