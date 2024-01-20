// import machine {pin}
// import time {sleep_ms}

pin_setup(led3, out)

for {
	pin_high(led3)
	sleep_ms(500)
	pin_low(led3)
	sleep_ms(500)
}
