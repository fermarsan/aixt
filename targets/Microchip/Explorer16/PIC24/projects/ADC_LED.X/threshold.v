import adc
import pin_fn as pin

for {
	if adc.read(pot) > 512 {
		pin.high(led3)
	} else {
		pin.low(led3)
	}
}