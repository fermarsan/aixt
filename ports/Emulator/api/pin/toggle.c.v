// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// toggle function toggles the logic value of a specific pin
pub fn toggle(name int) {   
    pin.pins[name] ^= int(1)
    pin.update()
}