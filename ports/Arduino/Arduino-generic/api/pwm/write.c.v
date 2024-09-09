// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pwm

//Writes an analog value (PWM wave) to a pin
@[inline]
pub fn write(name int, value int) {
	C.analogWrite(name, value)
} 
	