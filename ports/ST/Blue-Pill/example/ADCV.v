import pin
import adc

pin.setup(p5, pin.input)
pin.setup(p10, pin.output)
pin.setup(p11, pin.output)

for {
	if 400 <= adc.read(p5) {
		pin.high(p10)
		pin.low(p11)
	} else {
		pin.high(p11)
		pin.low(p10)
	}
}
