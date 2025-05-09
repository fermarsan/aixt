// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management Nucleo-L031K6
module pin

// pin names
@[as_macro] pub const pa0	=	u8(C.PA0)
// del PA1 al PA14    
@[as_macro] pub const pa15	=	u8(C.PA15) 

// lo mismo para PB y PC

@[as_macro] pub const pc6	=	u8(C.PC6) 

// pin modes
@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
