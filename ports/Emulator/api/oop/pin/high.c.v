// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin

// high function puts a high value (logic 1) to a specific pin
@[inline]
pub fn (mut pin_object Pin) high() {   
    pin__pins[pin_object.id] = 1
    pin.update()
}
