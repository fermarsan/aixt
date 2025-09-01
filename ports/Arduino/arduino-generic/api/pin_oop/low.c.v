// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
module pin_oop

// low puts a low value (logic 0) to a specific pin
// @[as_macro]
@[inline]
pub fn (p Pin) low() {   
    C.digitalWrite(p.id, C.LOW)
}
