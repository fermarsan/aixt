// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// Pin-port functions for 16F8x
module port

// port names
@[as_macro] pub const a = 0
@[as_macro] pub const b = 1
@[as_macro] pub const c = 2
@[as_macro] pub const d = 3
@[as_macro] pub const e = 4

// port common modes
@[as_macro] pub const all_inputs = 0b11111111
@[as_macro] pub const all_outputs = 0b00000000
