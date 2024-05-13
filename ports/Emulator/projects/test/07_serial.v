import time { sleep_ms }
import uart

for _ in 0..5 {
    uart.println("Hello, world!")	// default uart
    sleep_ms(1500)
}