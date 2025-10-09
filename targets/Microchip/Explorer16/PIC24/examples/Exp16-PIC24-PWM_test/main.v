import pin
import pwm

pin.setup(led1, pin.output)	// PWM pin as output

for {
	pwm.write(led1, 50)
}