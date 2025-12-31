// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// Pin-port functions for 16F8x
module port

@[as_macro] pub const a = 0 // port ids
@[as_macro] pub const b = 1

@[as_macro] pub const all_inputs = 0b11111111 // port common modes
@[as_macro] pub const all_outputs = 0b00000000
