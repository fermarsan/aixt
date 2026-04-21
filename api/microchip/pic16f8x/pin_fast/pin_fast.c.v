// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F8x
module pin_fast

@[as_macro] pub const _0 = u8(0)  // pin numbers
@[as_macro] pub const _1 = u8(1)
@[as_macro] pub const _2 = u8(2)
@[as_macro] pub const _3 = u8(3)
@[as_macro] pub const _4 = u8(4)

@[as_macro] pub const output = u8(0)    // pin modes
@[as_macro] pub const input = u8(1)

@[as_macro] pub const port_a = C.A  // port ids
@[as_macro] pub const port_b = C.B
