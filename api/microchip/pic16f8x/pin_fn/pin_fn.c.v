// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F8x
module pin_fn

@[as_macro] pub const a0 = u8(0)  // pin ids
@[as_macro] pub const a1 = u8(1)
@[as_macro] pub const a2 = u8(2)
@[as_macro] pub const a3 = u8(3)
@[as_macro] pub const a4 = u8(4) // pins from a5 to a7 not implemented

@[as_macro] pub const b0 = u8(8)
@[as_macro] pub const b1 = u8(9)
@[as_macro] pub const b2 = u8(10)
@[as_macro] pub const b3 = u8(11)
@[as_macro] pub const b4 = u8(12)
@[as_macro] pub const b5 = u8(13)
@[as_macro] pub const b6 = u8(14)
@[as_macro] pub const b7 = u8(15)

// IRQ (INT) pin
@[as_macro] pub const irq = u8(8)

@[as_macro] pub const output = u8(0)    // pin modes
@[as_macro] pub const input = u8(1)
