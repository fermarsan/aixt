// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F87x
module pin_fast


@[as_macro] pub const a0 = u8(0)    // pin ids as macros
@[as_macro] pub const a1 = u8(1)
@[as_macro] pub const a2 = u8(2)
@[as_macro] pub const a3 = u8(3)
@[as_macro] pub const a4 = u8(4)
@[as_macro] pub const a5 = u8(5)

@[as_macro] pub const b0 = u8(8)
@[as_macro] pub const b1 = u8(9)
@[as_macro] pub const b2 = u8(10)
@[as_macro] pub const b3 = u8(11)
@[as_macro] pub const b4 = u8(12)
@[as_macro] pub const b5 = u8(13)
@[as_macro] pub const b6 = u8(14)
@[as_macro] pub const b7 = u8(15)

@[as_macro] pub const c0 = u8(16)
@[as_macro] pub const c1 = u8(17)
@[as_macro] pub const c2 = u8(18)
@[as_macro] pub const c3 = u8(19)
@[as_macro] pub const c4 = u8(20)
@[as_macro] pub const c5 = u8(21)
@[as_macro] pub const c6 = u8(22)
@[as_macro] pub const c7 = u8(23)

@[as_macro] pub const d0 = u8(24)
@[as_macro] pub const d1 = u8(25)
@[as_macro] pub const d2 = u8(26)
@[as_macro] pub const d3 = u8(27)
@[as_macro] pub const d4 = u8(28)
@[as_macro] pub const d5 = u8(29)
@[as_macro] pub const d6 = u8(30)
@[as_macro] pub const d7 = u8(31)

@[as_macro] pub const e0 = u8(32)
@[as_macro] pub const e1 = u8(33)
@[as_macro] pub const e2 = u8(34)

// IRQ (INT) pin
@[as_macro] pub const irq = u8(8)

@[as_macro] pub const output = u8(0)    // port modes
@[as_macro] pub const input = u8(1)

@[as_macro] pub const port_a = u8(C.A)  // port ids as macros
@[as_macro] pub const port_b = u8(C.B)
@[as_macro] pub const port_c = u8(C.C)
@[as_macro] pub const port_d = u8(C.D)
@[as_macro] pub const port_e = u8(C.E)
