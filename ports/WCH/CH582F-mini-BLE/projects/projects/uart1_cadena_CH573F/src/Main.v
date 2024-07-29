import time
import uart

uart.setup(115200)
count := u8(0)

for {
	uart.print('counter')
	uart.println(' = ${count}...')
	count++
	time.sleep_ms(500)
}