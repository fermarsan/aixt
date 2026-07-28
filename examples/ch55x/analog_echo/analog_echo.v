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

// Configurar el pin PWM (P3.4)
pwm.setup_pin(pwm.ch2_2)

for {
    // Leer el valor analógico del canal ADC0 (P1.1)
    value := adc.read(adc.ch0)

    // Enviar el valor leído al módulo PWM
    pwm.write(pwm.ch2_2, u8(value))

    // Esperar 10 ms
    time.sleep_ms(10)
}