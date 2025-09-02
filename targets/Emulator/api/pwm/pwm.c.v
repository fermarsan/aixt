// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
module pwm

#include <stdio.h>
#include <stdlib.h>

//PWM names
pub const ch0 = 0
pub const ch1 = 1


__global (
    pwm__duty = [0, 0]
)

pub fn print(duty int) {
    for i in 1..51 {
        if i <= duty/2 {
            C.printf('|')
        } else {
            C.printf('_')
        }
    }
    C.printf('\n')
}

pub fn update() {
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
    C.printf(' Aixt virtual PWM outputs\n')
    C.printf('\t\t\t\t    PWM 0 :  %d %%\n', pwm__duty[0])
    pwm.print(pwm__duty[0])
    C.printf('\t\t\t\t    PWM 1 :  %d %%\n', pwm__duty[1])
    pwm.print(pwm__duty[1])
}

fn init() {
    pwm.update()
}

pub fn write(channel int, duty int) {
    pwm__duty[channel] = duty
    pwm.update()
}