// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin_oop

// write puts a logic value to a specific pin
pub fn write(name int, val int) {  
    pin__pins[name] = val
    pin_oop.update()
}