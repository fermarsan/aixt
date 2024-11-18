// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// low puts a low value (logic 0) to a specific pin
@[as_macro]
pub fn low(name u8) {   
    C.digitalWrite(name, C.LOW)
}
