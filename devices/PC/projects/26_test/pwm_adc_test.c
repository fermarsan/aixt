// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm_adc_test.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: PWM + ADC emulation testing.
#include "../../api/time.c"
#include "../../api/machine/machine__pwm.c"
#include "../../api/machine/machine__adc.c"

int main() {
    int value = 0;
    value = adc1_read();
    pwm1_duty(value*2);
    value = adc2_read();
    pwm2_duty(value+10);
}