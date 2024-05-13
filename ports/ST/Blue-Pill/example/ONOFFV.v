import time {sleep_ms}
import pin

<<<<<<< HEAD
pin__setup(p25, pin__output)
=======
<<<<<<< HEAD
pin.setup(P25, pin.out)
=======
pin__setup(P25, pin__output)
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77
>>>>>>> 81843babddc9ac24b41b0fffc375102ccc219794

 for{
    pin__high(p25)
	time__sleep_ms(1000)
	pin__low(p25)
	time__sleep_ms(1000)
}  
