// Project name: Timer Interrupt Test with Percent Compare (3 LEDs)
// Author: Fernando M. Santa & Santiago Farfán
// Date: 09/05/2025
// Board: STM32G431Coreboard

import timer8
import pin
import time

@[timer8_isr]
fn overflow_interrupt() {
    pin.high(pin.pa7)
    time.sleep_ms(200)
    pin.low(pin.pa7)
}

@[timer8_isr: 'timer8.compare_ch1']
fn compare_channel_1_interrupt() {
    pin.high(pin.pa14)
    time.sleep_ms(200)
    pin.low(pin.pa14)
}

@[timer8_isr: 'timer8.compare_ch2']
fn compare_channel_2_interrupt() {
    pin.high(pin.pa15)
    time.sleep_ms(200)
    pin.low(pin.pa15)
}

fn main() {
    // Configurar pines como salida
    pin.setup(pin.pa7, pin.output)   // Overflow (100%)
    pin.setup(pin.pa14, pin.output)   // Canal 1 (50%)
    pin.setup(pin.pa15, pin.output)  // Canal 2 (75%)

    // Configurar timer8 a 1 Hz (1 segundo por ciclo)
    timer8.setup(0.5, timer8.hz)

    // Especificar porcentaje en que se disparan los canales de comparación
    timer8.write_percent_channel(1, 50) // Canal 1 a los 500 ms
    timer8.write_percent_channel(2, 75) // Canal 2 a los 750 ms

    // Habilitar interrupciones
    timer8.irq_enable()
    timer8.compare_irq_enable(timer8.compare_ch1)
    timer8.compare_irq_enable(timer8.compare_ch2)

    // Iniciar timer
    timer8.restart()
}
