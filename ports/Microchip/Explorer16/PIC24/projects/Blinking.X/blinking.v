import time { sleep_ms }
import pin
import port

// pin.setup(a0, pin.out)

for {
	// pin.high(led3)
	port.write(A, 0b11001100)
	sleep_ms(500)
	// pin.low(led3)
	port.write(A, 0b00110011)
	sleep_ms(500)
}