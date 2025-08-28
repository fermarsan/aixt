// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// toggle function toggles the logic value of a specific pin
pub fn toggle(pin_id int) {   
    pin__pins[pin_id] ^= int(1)
    pin.update()
}