// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// PWM functions (Arduino Nano - ATmega328P port)
module pwm_fn

fn C.analogWrite(id u8, value u8)

// write function puts an analog value (PWM wave) to a pin
@[as_macro]
pub fn write(id u8, value u8) {
	C.analogWrite(id, value)
} 

// setup_pin function configures as output a PWM pin
@[as_macro]
pub fn setup_pin(id u8) {
	C.pinMode(id, C.OUTPUT)
} 