import pin
import adc

pin.setup(p14, input)
pin.setup(p20 output)
pin.setup(p9, output)

for {
	if 400 <= adc__read(p14) {
		pin__high(p20)
		pin__low(p9)
	} else {
		pin__high(p9)
		pin__low(p20)
	}
}
