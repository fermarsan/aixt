// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pwm

//Writes an analog value (PWM wave) to a pin
@[inline]
pub fn write(name u8, value u8) {
	C.analogWrite(name, value)
} 
	