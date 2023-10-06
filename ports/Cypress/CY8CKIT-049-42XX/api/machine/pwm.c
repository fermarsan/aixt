// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
//              (CY8CKIT-049-42XX)

void pwm_duty(int pwm_id, int duty) {
    if (pwm_id==1){
        pwm0_WriteCompare(duty*655);
    }
    else if (pwm_id==2){
        pwm1_WriteCompare(duty*655);
    }
    else if (pwm_id==3){
        pwm2_WriteCompare(duty*655);
    }
    else if (pwm_id==4){
        pwm3_WriteCompare(duty*655);
    }
}