// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
module pin_oop

// setup configures a pin's input/output mode
// @[as_macro]
@[inline]
pub fn (p Pin) setup(mode u8) {   
    C.pinMode(p.id, mode)
}
