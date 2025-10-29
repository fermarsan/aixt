// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management STM32F411Core
module pin

// pin names A
@[as_macro] pub const pa0	=	0
@[as_macro] pub const pa1	=	1
@[as_macro] pub const pa2	=	2
@[as_macro] pub const pa3	=	3
@[as_macro] pub const pa4	=	4
@[as_macro] pub const pa5	=	5
@[as_macro] pub const pa6	=	6
@[as_macro] pub const pa7	=	7
@[as_macro] pub const pa8	=	8
@[as_macro] pub const pa9	=	9
@[as_macro] pub const pa10	=	10
@[as_macro] pub const pa11	=	11
@[as_macro] pub const pa12	=	12
@[as_macro] pub const pa13	=	13
@[as_macro] pub const pa14	=	14
@[as_macro] pub const pa15	=	15

// lo mismo para PB
@[as_macro] pub const pb0	=	16
@[as_macro] pub const pb1	=	17
@[as_macro] pub const pb2	=	18
@[as_macro] pub const pb3	=	19
@[as_macro] pub const pb4	=	20
@[as_macro] pub const pb5	=	21
@[as_macro] pub const pb6	=	22
@[as_macro] pub const pb7	=	23
@[as_macro] pub const pb8	=	44
@[as_macro] pub const pb9	=	25
@[as_macro] pub const pb10	=	26
@[as_macro] pub const pb12	=	27
@[as_macro] pub const pb13	=	28
@[as_macro] pub const pb14	=	29
@[as_macro] pub const pb15	=	30

// lo mismo para PC
@[as_macro] pub const pc13	=	31
@[as_macro] pub const pc14	=	32
@[as_macro] pub const pc15	=	33

@[as_macro] pub const led0 = 31	// builtin LED
@[as_macro] pub const sw0 = 0		// builtin Switch	