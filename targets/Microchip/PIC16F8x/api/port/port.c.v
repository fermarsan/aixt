// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions for 16F8x
module port

// port names
@[as_macro] pub const a = 0
@[as_macro] pub const b = 1


// port common modes
@[as_macro] pub const all_inputs = 0b11111111
@[as_macro] pub const all_outputs = 0b00000000
