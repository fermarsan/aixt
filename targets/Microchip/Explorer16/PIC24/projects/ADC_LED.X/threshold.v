import adc
import pin

for {
	if adc.read(pot) > 512 {
		pin.high(led3)
	} else {
		pin.low(led3)
	}
}