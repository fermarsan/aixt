// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
module pwm

fn duty(pwm int, duty int) {
    duty__[pwm] = duty
    pwm__update()
}