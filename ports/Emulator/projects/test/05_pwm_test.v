pwm2_duty(100)
for i in 1..100 {
    sleep(1)
    pwm1_duty(i)
    pwm2_duty(100-i)
}
