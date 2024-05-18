// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// toggle function toggles the logic value of a specific pin
pub fn toggle(pin_name int) {   
    pins__[pin_name] ^= 1
    pin.update()
}