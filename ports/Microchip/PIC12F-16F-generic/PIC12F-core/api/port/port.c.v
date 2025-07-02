// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin-port functions (PIC12F8x port)
module port

// port names
@[as_macro]	pub const a = 0
@[as_macro]	pub const b = 1
@[as_macro]	pub const c = 2
@[as_macro]	pub const d = 3
@[as_macro]	pub const e = 4

// port common modes
@[as_macro]	pub const all_inputs =  0b11111111
@[as_macro]	pub const all_outputs = 0b00000000