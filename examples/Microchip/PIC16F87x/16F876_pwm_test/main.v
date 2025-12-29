// Project name: Inverter
// Author: Fernando M. Santa
// Date: 2024-2025
// PWM 2-channel test
// PIC16F876 fosc = 20Mhz
import pwm

pwm.setup(pwm.ch1 & pwm.ch2, 100, pwm.f_low)
pwm.write(pwm.ch1, 25)
pwm.write(pwm.ch2, 75)

for {
}
