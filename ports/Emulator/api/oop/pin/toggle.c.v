// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin

// toggle function toggles the logic value of a specific pin
@[inline]
pub fn (mut pin_object Pin) toggle() {   
    pin__pins[pin_object.id] ^= int(1)
    pin.update()
}
