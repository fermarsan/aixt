// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
#include <stdio.h>
#include <stdlib.h>

// module main

__global (
    duty1__ int
    duty2__ int
)

fn pwm_print(duty int) {
    for i__ := 1; i__ <= 50; i__++ {
        if i__ <= duty/2 {
            printf('|')
        } else {
            printf('_')
        }
    }
    printf('\n')
}

fn pwm_update() {
    system('clear')
    printf(' Aixt virtual PWM outputs\n')
    printf('\t\t\t\t    PWM 1 :  %l %%\n', duty1__)
    pwm_print(duty1__)
    printf('\t\t\t\t    PWM 2 :  %l %%\n', duty2__)
    pwm_print(duty2__)
}

fn pwm1_duty(duty int) {
    duty1__ = duty
    pwm_update()
}

fn pwm2_duty(duty int) {
    duty2__ = duty
    pwm_update()
}