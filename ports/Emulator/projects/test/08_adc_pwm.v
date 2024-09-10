import adc
import pwm

value := adc.read(an0)

pwm.write(pwm1, value)