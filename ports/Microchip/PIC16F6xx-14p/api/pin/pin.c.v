// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions for 16F630-676
module pin

// pin names as macros
@[as_macro] pub const a0 = 0
@[as_macro] pub const a1 = 1
@[as_macro] pub const a2 = 2
@[as_macro] pub const a3 = 3
@[as_macro] pub const a4 = 4
@[as_macro] pub const a5 = 5

@[as_macro] pub const c0 = 16
@[as_macro] pub const c1 = 17
@[as_macro] pub const c2 = 18
@[as_macro] pub const c3 = 19
@[as_macro] pub const c4 = 20
@[as_macro] pub const c5 = 21

// IRQ (INT) pin
@[as_macro] pub const irq = 2

// pin modes as macros
@[as_macro] pub const output = 0
@[as_macro] pub const input = 1

// port names as macros
@[as_macro] pub const port_a = C.A
@[as_macro] pub const port_c = C.C
