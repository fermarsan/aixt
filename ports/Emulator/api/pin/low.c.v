// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module pin

// pin_high puts a low value (logic 0) to a specific pin
pub fn low(name int) {   
    pin__pins[name] = 0
    pin.update()
}
