// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F630-676
module pin_fn

@[as_macro] pub const a0 = u8(0)
@[as_macro] pub const a1 = u8(1)
@[as_macro] pub const a2 = u8(2)
@[as_macro] pub const a3 = u8(3)
@[as_macro] pub const a4 = u8(4)
@[as_macro] pub const a5 = u8(5)

@[as_macro] pub const c0 = u8(16)
@[as_macro] pub const c1 = u8(17)
@[as_macro] pub const c2 = u8(18)
@[as_macro] pub const c3 = u8(19)
@[as_macro] pub const c4 = u8(20)
@[as_macro] pub const c5 = u8(21)

// IRQ (INT) pin
@[as_macro] pub const irq = u8(2)

// pin modes as macros
@[as_macro] pub const output = u8(0)
@[as_macro] pub const input = u8(1)

// port names as macros
@[as_macro] pub const port_a = u8(C.A)
@[as_macro] pub const port_c = u8(C.C)
