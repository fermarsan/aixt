import pin
import pwm

pin.setup(led1, output)	// PWM pin as output

for {
	pwm.write(led1, 50)
}