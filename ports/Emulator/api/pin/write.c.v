// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module pin

// write puts a logic value to a specific pin
pub fn write(pin_name int, val int) {  
    pins__[pin_name] = val
    pin__update()
}