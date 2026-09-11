// Project name: analog_echo
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026 
// ch55x boards
import time
import adc_fn as adc
import pwm_fn as pwm

// Configure the PWM pin (P3.4)
pwm.setup_pin(pwm.ch2_2)

for {
    // Read the analog value from channel ADC0 (P1.1)
    value := adc.read(adc.ch0)

    // Send the read value to the PWM module
    pwm.write(pwm.ch2_2, u8(value))

    // Wait 10 ms
    time.sleep_ms(10)
}