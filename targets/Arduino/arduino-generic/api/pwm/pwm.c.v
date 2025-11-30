// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM functions (Arduino Nano - ATmega328P port)
module pwm

fn C.analogwrite(id u8, value u8)

//Writes an analog value (PWM wave) to a pin
@[as_macro]
pub fn write(id u8, value u8) {
	C.analogWrite(id, value)
} 