// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32G431Coreboard

import timer1
import pin
import time

@[timer1_isr]
fn overflow_interrupt() {
    pin.high(pin.pa8)
    time.sleep_ms(500)
    pin.low(pin.pa8)
}

@[timer1_isr:'timer1.compare_ch1']
fn compare_channel_1_interrupt() {
    pin.high(pin.pa9)
    time.sleep_ms(500)
    pin.low(pin.pa9)
}

fn main() {
    // LED 1 en PA8 (canal 1) - 25%
    pin.setup(pin.pa8, pin.output)
    // LED 2 en PA9 (canal 2) - 50%
    pin.setup(pin.pa9, pin.output)
    // LED 3 en PA10 (canal 3) - 75%
    pin.setup(pin.pa10, pin.output)

    // Configurar timer1 con una frecuencia de actualización de 1000ms (1Hz)
    timer1.setup(1, timer1.hz)
    timer1.irq_enable()
    

    // Configurar PWM para cada canal
    timer1.setmode(1, timer1.pwm1, pin.pa8)
    timer1.setmode(2, timer1.pwm1, pin.pa9)
    timer1.setmode(3, timer1.pwm1, pin.pa10)

    // Aplicar duty cycles diferentes
    timer1.write_percent_channel(1, 25)
    timer1.write_percent_channel(2, 50)
    timer1.write_percent_channel(3, 75)

    timer1.compare_irq_enable(timer1.compare_ch1)

    // Iniciar el timer
    timer1.restart()
}
