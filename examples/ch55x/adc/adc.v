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
    // Leer el canal ADC0 (P1.1)
    value := adc.read(adc.ch0)

    // Comparar el valor leído
    if value > 127 {
        pin.high(pin.led0)
    } else {
        pin.low(pin.led0)
    }

    // Esperar 20 ms
    time.sleep_ms(20)
}