// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// write puts a logic value to a specific pin
@[inline]
pub fn write(name u8, val u8) {  
    C.digitalWrite(name, val)
}