// Project name: analog_echo
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026 
// ch55x boards
import time
import adc
import adc_fn
import pwm
import pwm_fn

// Configurar el pin PWM (P3.4)
pwm_fn.setup_pin(pwm.ch2_2)

for {
    // Leer el valor analógico del canal ADC0 (P1.1)
    value := adc_fn.read(adc.ch0)

    // Enviar el valor leído al módulo PWM
    pwm_fn.write(pwm.ch2_2, u8(value))

    // Esperar 10 ms
    time.sleep_ms(10)
}