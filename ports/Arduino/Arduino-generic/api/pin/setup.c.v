// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// setup configures a pin's input/output mode
@[inline]
pub fn setup(name int, mode int) {   
    C.pinMode(name, mode)
}