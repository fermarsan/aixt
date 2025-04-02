// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module adc

//Reads the value from the specified analog pin
@[inline]
pub fn read(PIN_NAME) {
C.analogRead(PIN_NAME)  
}