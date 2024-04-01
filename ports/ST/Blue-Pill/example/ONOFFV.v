import time {sleep_ms}
import pin

pin.setup(P25, pin.out)

 for{
    pin__high(P25)
	time__sleep_ms(1000)
	pin__low(P25)
	time__sleep_ms(1000)
}  
