// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module time

// sleep is a delay function in milliseconds for the Aixt PC port. 
@[inline]
pub fn sleep_ms(tms int) {
	C.delay(tms)
}