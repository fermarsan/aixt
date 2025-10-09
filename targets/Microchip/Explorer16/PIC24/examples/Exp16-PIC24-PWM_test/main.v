import pin
import pwm

pin.setup(pin.led1, pin.output)	// PWM pin as output

for {
	pwm.write(pin.led1, 50)
}