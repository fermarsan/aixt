// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin_oop

// toggle function toggles the logic value of a specific pin
@[inline]
pub fn (mut pin Pin) toggle() {   
    pin__pins[pin.id] ^= int(1)
    pin_oop.update()
}