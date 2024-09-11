import pin
import adc

pin.setup(p5, input)
pin.setup(p10, output)
pin.setup(p11, output)

for {
	if 400 <= adc.read(p5) {
		pin.high(p10)
		pin.low(p11)
	} else {
		pin.high(p11)
		pin.low(p10)
	}
}
