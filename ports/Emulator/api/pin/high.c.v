// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module pin

// pin.high puts a high value (logic 1) to a specific pin
pub fn high(name int) {   
    pin__pins[name] = 1
    pin.update()
}