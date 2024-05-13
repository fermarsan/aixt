import pin
import adc

pin.setup(p14, pin__input)
pin.setup(p20 pin__output)
pin.setup(p9, pin__output)

for {
	if 400 <= adc__read(p14) {
		pin__high(p20)
		pin__low(p9)
	} else {
		pin__high(p9)
		pin__low(p20)
	}
}
