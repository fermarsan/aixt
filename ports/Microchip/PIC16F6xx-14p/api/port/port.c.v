// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2015
// License: MIT
//
// Description: Pin-port functions for 16F630-676
module port

// port names
@[as_macro] pub const a = 0
@[as_macro] pub const c = 2

// port common modes
@[as_macro] pub const all_inputs = 0b11111111
@[as_macro] pub const all_outputs = 0b00000000
