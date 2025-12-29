// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// PWM functions (Arduino Nano - ATmega328P port)
module pwm

fn C.analogWrite(id u8, value u8)

// PWM is a struct that represents an PWM pin
pub struct PWM {
pub mut:
    id      u8
}

// new returns a new PWM instance
pub fn PWM.new(id u8) PWM {
    return PWM {
        id:     id
    }
}

//Writes an analog value (PWM wave) to a pin
@[inline]
pub fn (mut p PWM) write(value u8) {
	C.analogWrite(p.id, value)
}

// setup_pin function configures as output a PWM pin
@[inline]
pub fn (mut p PWM) setup_pin() {
	C.pinMode(p.id, C.OUTPUT)
}
