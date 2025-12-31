// Author: Fernando M. Santa
// Date: 2025

module pin

#include "toggle.c"

fn C.DIGITAL_TOGGLE(id u8)

// toggle function toggles the value to a specific pin
// @[as_macro]
@[inline]
pub fn (mut p Pin) toggle() {
    C.DIGITAL_TOGGLE(p.id)
}
