// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: machine__pwm.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
#include <stdio.h>
#include <stdlib.h>

int duty1 = 10;
int duty2 = 80;

void pwm_print(int duty) {
    for(int i=1; i<=50; i++) {
        if(i <= (duty/2)) {
            printf("|");
        } else {
            printf("_");
        }
    }
}

void pwm_update(void) {
    system("clear");
    printf(" Aixt virtual PWM outputs\n");
    printf("PWM 1 : %d%%\n", duty1);
    pwm_print(duty1);
    printf("\nPWM 2 : %d%%\n", duty2);
    pwm_print(duty2);
    printf("\n");
}

// void pwm1_duty(int duty) {

// }