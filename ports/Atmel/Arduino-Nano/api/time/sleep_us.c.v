// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module time

// sleep is a delay function in microseconds for the Aixt PC port. 
@[inline]
pub fn sleep_us(tus int) {
	C.delayMicroseconds(tus)
}