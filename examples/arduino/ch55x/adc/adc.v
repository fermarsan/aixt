// Project name: adc
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026 
// ch55x boards
import time
import adc_fn as adc
import pin_fn as pin

pin.setup(pin.led0, pin.output)

for {
    // Read the ADC0 channel (P1.1)
    value := adc.read(adc.ch0)

    // Compare the read value
    if value > 127 {
        pin.high(pin.led0)
    } else {
        pin.low(pin.led0)
    }

    // Wait 20 ms
    time.sleep_ms(20)
}