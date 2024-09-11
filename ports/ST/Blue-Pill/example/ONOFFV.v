import time {sleep_ms}
import pin

<<<<<<< HEAD
pin.setup(p25, output)
=======
<<<<<<< HEAD
pin.setup(P25, pin.out)
=======
pin.setup(P25, output)
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77
>>>>>>> 81843babddc9ac24b41b0fffc375102ccc219794

 for{
    pin.high(p25)
	time__sleep_ms(1000)
	pin.low(p25)
	time__sleep_ms(1000)
}  
