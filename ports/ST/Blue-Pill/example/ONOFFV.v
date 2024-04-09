import time {sleep_ms}
import pin

pin__setup(p25, pin__output)

 for{
    pin__high(p25)
	time__sleep_ms(1000)
	pin__low(p25)
	time__sleep_ms(1000)
}  
