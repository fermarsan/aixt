// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
module pwm

#include <stdio.h>
#include <stdlib.h>
#include "pwm.c"

const (
    ch0 = 0
    ch1 = 1
)

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
    main.clear_screen()
    C.printf(' Aixt virtual PWM outputs\n')
    C.printf('\t\t\t\t    PWM 0 :  %ld %%\n', pwm__duty[0])
    pwm.print(pwm__duty[0])
    C.printf('\t\t\t\t    PWM 1 :  %ld %%\n', pwm__duty[1])
    pwm.print(pwm__duty[1])
}

fn init() {
    pwm.update()
}