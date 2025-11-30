// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH573F)

module pin

@[as_macro] pub const a4 =  A, 4
@[as_macro] pub const a5 =  A, 5
@[as_macro] pub const a8 =  A, 8
@[as_macro] pub const a9 =  A, 9
@[as_macro] pub const a10 = A, 10
@[as_macro] pub const a11 = A, 11
@[as_macro] pub const a12 = A, 12
@[as_macro] pub const a13 = A, 13
@[as_macro] pub const a14 = A, 14
@[as_macro] pub const a15 = A, 15
@[as_macro] pub const b4 =  B, 4
@[as_macro] pub const b7 =  B, 7
@[as_macro] pub const b10 = B, 10
@[as_macro] pub const b11 = B, 11
@[as_macro] pub const b12 = B, 12
@[as_macro] pub const b13 = B, 13
@[as_macro] pub const b14 = B, 14
@[as_macro] pub const b15 = B, 15
@[as_macro] pub const b22 = B, 22
@[as_macro] pub const b23 = B, 23

@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)
