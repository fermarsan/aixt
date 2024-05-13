import time { sleep_ms }
import uart

for _ in 0..5 {
    uart.print(0, "Welcome ")	// 0 uart
    uart.print(1, "to Aixt ")	// 1 uart
    uart.println(2, "project!")	// 2 uart
    sleep_ms(1500)
}