// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin_oop

// toggle function toggles the logic value of a specific pin
pub fn toggle(name int) {   
    pin__pins[name] ^= int(1)
    pin_oop.update()
}