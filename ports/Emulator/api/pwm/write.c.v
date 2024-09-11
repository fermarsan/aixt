// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
module pwm

pub fn write(channel int, duty int) {
    pwm.duty[channel] = duty
    pwm.update()
}