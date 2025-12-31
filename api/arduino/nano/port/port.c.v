// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// Pin-port functions
module port

@[as_macro] pub const b = 0   // Port ids
@[as_macro] pub const c = 1
@[as_macro] pub const d = 2

@[as_macro] pub const all_inputs = 0b11111111   // Common setups
@[as_macro] pub const all_outputs = 0b00000000
