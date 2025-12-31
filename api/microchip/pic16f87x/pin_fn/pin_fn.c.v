// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for 16F87x
module pin_fn

@[as_macro] pub const a0 = 0 // PORTA pins
@[as_macro] pub const a1 = 1
@[as_macro] pub const a2 = 2
@[as_macro] pub const a3 = 3
@[as_macro] pub const a4 = 4
@[as_macro] pub const a5 = 5

@[as_macro] pub const b0 = 8 // PORTB pins
@[as_macro] pub const b1 = 9
@[as_macro] pub const b2 = 10
@[as_macro] pub const b3 = 11
@[as_macro] pub const b4 = 12
@[as_macro] pub const b5 = 13
@[as_macro] pub const b6 = 14
@[as_macro] pub const b7 = 15

@[as_macro] pub const c0 = 16 // PORTC pins
@[as_macro] pub const c1 = 17
@[as_macro] pub const c2 = 18
@[as_macro] pub const c3 = 19
@[as_macro] pub const c4 = 20
@[as_macro] pub const c5 = 21
@[as_macro] pub const c6 = 22
@[as_macro] pub const c7 = 23

@[as_macro] pub const d0 = 24 // PORTA pins
@[as_macro] pub const d1 = 25
@[as_macro] pub const d2 = 26
@[as_macro] pub const d3 = 27
@[as_macro] pub const d4 = 28
@[as_macro] pub const d5 = 29
@[as_macro] pub const d6 = 30
@[as_macro] pub const d7 = 31

@[as_macro] pub const e0 = 32
@[as_macro] pub const e1 = 33
@[as_macro] pub const e2 = 34

// IRQ (INT) pin
@[as_macro] pub const irq = 8 // RB0/INT

@[as_macro] pub const output = 0 // pin modes
@[as_macro] pub const input = 1
