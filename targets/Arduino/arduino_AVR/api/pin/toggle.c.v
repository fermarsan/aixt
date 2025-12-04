// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
module pin

#include "toggle.c"

// toggle function toggles the value to a specific pin
@[as_macro]
pub fn toggle(id u8) {   
    C.DIGITAL_TOGGLE(id)
}