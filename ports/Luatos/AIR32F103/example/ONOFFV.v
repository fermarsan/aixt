import time {sleep_ms}
import pin

pin.setup(p15, pin__output)

pin.setup(p23, pin__output)

pin.setup(p24, pin__output)

 for{
    pin__high(p15)
	time__sleep_ms(1000)
	pin__low(p15)
	time__sleep_ms(1000)

	pin__high(p23)
	time__sleep_ms(1000)
	pin__low(p23)
	time__sleep_ms(1000)

	pin__high(p24)
	time__sleep_ms(1000)
	pin__low(p24)
	time__sleep_ms(1000)
}  
