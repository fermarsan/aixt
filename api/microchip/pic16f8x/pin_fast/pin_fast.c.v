// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F8x
module pin_fast

@[as_macro] pub const a0 = 0  // pin ids
@[as_macro] pub const a1 = 1
@[as_macro] pub const a2 = 2
@[as_macro] pub const a3 = 3
@[as_macro] pub const a4 = 4 // pins from a5 to a7 not implemented

@[as_macro] pub const b0 = 8
@[as_macro] pub const b1 = 9
@[as_macro] pub const b2 = 10
@[as_macro] pub const b3 = 11
@[as_macro] pub const b4 = 12
@[as_macro] pub const b5 = 13
@[as_macro] pub const b6 = 14
@[as_macro] pub const b7 = 15

// IRQ (INT) pin
@[as_macro] pub const irq = 8

@[as_macro] pub const output = 0    // pin modes
@[as_macro] pub const input = 1

@[as_macro] pub const port_a = C.A  // port ids
@[as_macro] pub const port_b = C.B
