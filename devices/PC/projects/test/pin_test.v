import machine { pin }
import time { sleep }

for i in 1:10 {
	pin_high(C)
	sleep(1)
	pin_low(C)
	sleep(1)
}