// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module pin

// write puts a logic value to a specific pin
pub fn write(name int, val int) {  
    pin.pins[name] = val
    pin.update()
}