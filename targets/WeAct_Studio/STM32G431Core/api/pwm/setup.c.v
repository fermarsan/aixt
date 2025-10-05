// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM setup (STM32G431Core port)
module pwm

// setup function configures de PWM hardware
@[as_macro]
pub fn write(id u8, value u8) {
	C.analogWrite(id, value)
} 
	

