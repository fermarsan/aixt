// Project name:
// Author:
// Date:
// PIC16F877 fosc = 20Mhz
import adc
import pwm

adc.setup(adc.in0, adc.bits_8)
pwm.setup(pwm.ch1, 255, pwm.f_low)

for {
	x := adc.read_byte(0)
	pwm.write(pwm.ch1, x)
}
