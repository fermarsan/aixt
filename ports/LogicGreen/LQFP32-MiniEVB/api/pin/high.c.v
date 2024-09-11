// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// high function puts a high value (logic 1) to a specific pin
@[inline]
pub fn pin.high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}