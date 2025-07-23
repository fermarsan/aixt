// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions for 16F62x-648
module pin

// pin names as macros
@[as_macro] pub const a0 = 0
@[as_macro] pub const a1 = 1
@[as_macro] pub const a2 = 2
@[as_macro] pub const a3 = 3
@[as_macro] pub const a4 = 4
@[as_macro] pub const a5 = 5
@[as_macro] pub const a6 = 6
@[as_macro] pub const a7 = 7

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

// pin modes as macros
@[as_macro] pub const output = 0
@[as_macro] pub const input = 1

// port names as macros
@[as_macro] pub const port_a = C.A
@[as_macro] pub const port_b = C.B 
