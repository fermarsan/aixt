import uart
import time

for i in 0..5 {
	uart.println('Hello')
	time.sleep(1)
}
