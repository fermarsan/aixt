// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
#include <stdio.h>
#include <stdlib.h>

__duty1 := 0;
__duty2 := 0;

fn pwm_print(duty int) {
    for __i := 1; __i <= 50; __i++ {
        if __i <= (duty/2) {
            printf("|")
        } else {
            printf("_")
        }
    }
    printf("\n")
}

fn pwm_update() {
    system("clear")
    printf(" Aixt virtual PWM outputs\n")
    printf("\t\t\t\t    PWM 1 :  %d %%\n", __duty1)
    pwm_print(__duty1);
    printf("\t\t\t\t    PWM 2 :  %d %%\n", __duty2)
    pwm_print(__duty2)
}

fn pwm1_duty(duty int) {
    __duty1 = duty
    pwm_update()
}

fn pwm2_duty(duty int) {
    __duty2 = duty
    pwm_update()
}