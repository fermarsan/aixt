// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
module pin_oop

// write puts a logic value to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) write(val u8) {  
    C.digitalWrite(p.id, val)
}
