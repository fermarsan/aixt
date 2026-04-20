// Author: Fernando M. Santa
// Date: 2025
//
// ## Description
// Pin management functions for 16F6xx-20p
module pin_fn

@[as_macro] pub const a0 = u8(0)
@[as_macro] pub const a1 = u8(1)
@[as_macro] pub const a2 = u8(2)
@[as_macro] pub const a3 = u8(3)
@[as_macro] pub const a4 = u8(4)
@[as_macro] pub const a5 = u8(5)

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

// IRQ (INT) pin
@[as_macro] pub const irq = u8(2)

// pin modes as macros
@[as_macro] pub const output = u8(0)
@[as_macro] pub const input = u8(1)

// port names as macros
@[as_macro] pub const port_a = u8(C.A)
@[as_macro] pub const port_b = u8(C.B)
@[as_macro] pub const port_c = u8(C.C)
