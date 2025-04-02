import time { sleep_ms }
import uart
import uart2
import uart3

for _ in 0..5 {
    uart.print("Welcome ")	// 0 uart
    uart2.print("to Aixt ")	// 1 uart
    uart3.println("project!")	// 2 uart
    sleep_ms(1500)
}