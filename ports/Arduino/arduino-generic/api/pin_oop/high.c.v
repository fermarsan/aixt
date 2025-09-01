// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
module pin_oop

// high puts a high value (logic 1) to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) high() {   
    C.digitalWrite(p.id, C.HIGH)
}
