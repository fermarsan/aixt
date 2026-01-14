import pin_fn as pin
import pwm

pin.setup(pin.led3, pin.output)	// PWM pin as output

for {
	pwm.write(pin.led3, 50)
}