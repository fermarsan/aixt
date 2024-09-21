// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// setup configures a pin's input/output mode
@[inline]
pub fn setup(name u8, mode u8) {   
    C.pinMode(name, mode)
}