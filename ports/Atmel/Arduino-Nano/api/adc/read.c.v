// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module adc

//Reads the value from the specified analog pin
@[inline]
fn read(name int) int {
	return C.analogRead(name)
}