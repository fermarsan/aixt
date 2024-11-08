import pin
import adc

pin.setup(p14, pin.input)
pin.setup(p20 output)
pin.setup(p9, pin.output)

for {
	if 400 <= adc.read(p14) {
		pin.high(p20)
		pin.low(p9)
	} else {
		pin.high(p9)
		pin.low(p20)
	}
}
