// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
module pwm

#include <stdio.h>
#include <stdlib.h>

// PWM_names is the enumerated type for the PWM names
enum PWM_names {
    pwm_0 = 0
    pwm_1   
}

__global (
    duty__ = [0, 0]
)

pub fn print(duty int) {
    for i__ := 1; i__ <= 50; i__++ {
        if i__ <= duty/2 {
            printf('|')
        } else {
            printf('_')
        }
    }
    printf('\n')
}

pub fn update() {
    system(CLEAR_SCREEN)
    printf(' Aixt virtual PWM outputs\n')
    printf('\t\t\t\t    PWM 0 :  %ld %%\n', duty__[0])
    pwm__print(duty__[0])
    printf('\t\t\t\t    PWM 1 :  %ld %%\n', duty__[1])
    pwm__print(duty__[1])
}

fn init() {
    update()
}