import time {sleep_ms}
import pin



for {
<<<<<<< HEAD
	pin.high(led1)
	time.sleep_ms(5000)
	pin.low(led1)
	time.sleep_ms(5000)
}
=======
	pin.write(led1, 0)
	time.sleep_ms(500)
	pin.write(led1, 1)
	time.sleep_ms(500)
}
>>>>>>> 30f8f01e3d9a7f04e7c6db9c304c07f452a74a8b
