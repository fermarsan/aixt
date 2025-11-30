import pin
import time


value := pin.read(pin.x)
time.sleep(1)

pin.write(pin.a, value)
time.sleep_ms(500)