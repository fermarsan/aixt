// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// write puts a logic value to a specific pin
@[inline]
pub fn write(name int, val int) {  
    C.digitalWrite(name, val)
}