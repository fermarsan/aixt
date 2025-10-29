// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management STM32G431Core
module pin

// pin names A
@[as_macro] pub const pa0	=	192
@[as_macro] pub const pa1	=	193
@[as_macro] pub const pa2	=	194
@[as_macro] pub const pa3	=	195
@[as_macro] pub const pa4	=	196
@[as_macro] pub const pa5	=	197
@[as_macro] pub const pa6	=	198
@[as_macro] pub const pa7	=	199
@[as_macro] pub const pa8	=	8
@[as_macro] pub const pa9	=	9
@[as_macro] pub const pa10	=	10
@[as_macro] pub const pa11	=	11
@[as_macro] pub const pa12	=	12
@[as_macro] pub const pa15	=	13

// lo mismo para PB
@[as_macro] pub const pb0	=	200
@[as_macro] pub const pb1	=	201
@[as_macro] pub const pb2	=	202
@[as_macro] pub const pb3	=	19
@[as_macro] pub const pb4	=	20
@[as_macro] pub const pb5	=	21
@[as_macro] pub const pb6	=	22
@[as_macro] pub const pb7	=	23
@[as_macro] pub const pb8	=	44
@[as_macro] pub const pb9	=	25
@[as_macro] pub const pb10	=	26
@[as_macro] pub const pb11	=	203
@[as_macro] pub const pb12	=	204
@[as_macro] pub const pb13	=	29
@[as_macro] pub const pb14	=	205
@[as_macro] pub const pb15	=	206

// lo mismo para PC
@[as_macro] pub const pc4	=	207
@[as_macro] pub const pc6	=	33
@[as_macro] pub const pc10	=	34
@[as_macro] pub const pc11	=	35
@[as_macro] pub const pc13	=	36
@[as_macro] pub const pc14	=	37
@[as_macro] pub const pc15	=	38


@[as_macro] pub const led0 = 33	// builtin LED
@[as_macro] pub const sw0 = 36	// builtin Switch