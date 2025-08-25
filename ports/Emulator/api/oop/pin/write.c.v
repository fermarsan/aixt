// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin

// write puts a logic value to a specific pin
@[inline]
pub fn (mut pin_object Pin) write(val int) {  
    pin__pins[pin_object.id] = val
    pin.update()
}
