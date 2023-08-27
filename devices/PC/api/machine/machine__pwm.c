// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: machine__pwm.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
#include <stdio.h>
#include <stdlib.h>

int __duty1 = 10;
int __duty2 = 100;

void pwm_print(int duty) {
    // printf("[ ");
    for(int i=1; i<=50; i++) {
        if(i <= (duty/2)) {
            printf("|");
        } else {
            printf("_");
        }
    }
    printf("\n");// ]\n");
}

void pwm_update(void) {
    system("clear");
    printf(" Aixt virtual PWM outputs\n");
    printf("\t\t\t\t    PWM 1 :  %d %%\n", __duty1);
    pwm_print(__duty1);
    printf("\t\t\t\t    PWM 2 :  %d %%\n", __duty2);
    pwm_print(__duty2);
}

// void pwm1_duty(int duty) {

// }