import adc
import pwm

value := adc.read(adc.ch0)

pwm.write(pwm.ch1, value)