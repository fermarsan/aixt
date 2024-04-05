import pin
import adc

pin.setup(P5, pin__input)
pin.setup(P10, pin__output)
pin.setup(P11, pin__output)

for {
	if 400 <= adc_read(P5) {
		pin__high(P10)
		pin__low(P11)
	} else {
		pin__high(P11)
		pin__low(P10)
	}
}
