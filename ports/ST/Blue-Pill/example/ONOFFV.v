import time {sleep_ms}
import pin

<<<<<<< HEAD
pin.setup(P25, pin.out)
=======
pin__setup(P25, pin__output)
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77

 for{
    pin__high(P25)
	time__sleep_ms(1000)
	pin__low(P25)
	time__sleep_ms(1000)
}  
