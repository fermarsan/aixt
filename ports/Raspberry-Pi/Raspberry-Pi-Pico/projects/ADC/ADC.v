import pin
import adc

__global (
    val = 0
    )

pin.setup(gp13, output)
pin.setup(gp14, output)
pin.setup(gp15, output)
pin.setup(gp16, output)

for {

	val = adc.read(gp27)

	if val >= 0 && val < 255 {
		pin.high(gp13)
		pin.low(gp14)
		pin.low(gp15)
		pin.low(gp16)
	}

	if val >= 255 && val < 511 {
		pin.low(gp13)
		pin.high(gp14)
		pin.low(gp15)
		pin.low(gp16)
	}

	if val >= 511 && val < 767 {
		pin.low(gp13)
		pin.low(gp14)
		pin.high(gp15)
		pin.low(gp16)
	}

	if val >= 767 && val < 1023 {
		pin.low(gp13)
		pin.low(gp14)
		pin.low(gp15)
		pin.high(gp16)
	}
}
