// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin

// high function puts a low value (logic 0) to a specific pin
@[inline]
pub fn (mut pin_object Pin) low() {   
    pin__pins[pin_object.id] = 0
    pin.update()
}