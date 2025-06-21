import pin
import time


value := pin.read(pin.x)

time.sleep_ms(500)

pin.write(pin.a, value)