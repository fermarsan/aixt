import machine { pin }
import time { sleep_ms }

for {   //infinite loop
    pin_high(x)
    sleep_ms(500)
    pin_low(x)
    sleep_ms(500)
}
