void update() {
    system(CLEAR_SCREEN);
    printf(" Aixt virtual PWM outputs\n");
    printf("\t\t\t\t    PWM 0 :  %ld %%\n", duty__[0]);
    pwm__print(duty__[0]);
    printf("\t\t\t\t    PWM 1 :  %ld %%\n", duty__[1]);
    pwm__print(duty__[1]);
}