// Project name: Timer Interrupt Test with Percent Compare (3 LEDs)
// Author: Fernando M. Santa & Santiago Farfán
// Date: 09/05/2025
// Board: STM32F411Coreboard

import timer2
import pin
import time

@[timer2_isr]
fn overflow_interrupt() {
    pin.high(pin.pa0)
    time.sleep_ms(200)
    pin.low(pin.pa0)
}

@[timer2_isr: 'timer2.compare_ch1']
fn compare_channel_1_interrupt() {
    pin.high(pin.pa1)
    time.sleep_ms(200)
    pin.low(pin.pa1)
}

@[timer2_isr: 'timer2.compare_ch2']
fn compare_channel_2_interrupt() {
    pin.high(pin.pa2)
    time.sleep_ms(200)
    pin.low(pin.pa2)
}

fn main() {
    // Configurar pines como salida
    pin.setup(pin.pa0, pin.output)   // Overflow (100%)
    pin.setup(pin.pa1, pin.output)   // Canal 1 (50%)
    pin.setup(pin.pa2, pin.output)  // Canal 2 (75%)

    // Configurar timer2 a 1 Hz (1 segundo por ciclo)
    timer2.setup(0.5, timer2.hz)

    // Especificar porcentaje en que se disparan los canales de comparación
    timer2.write_percent_channel(1, 50) // Canal 1 a los 500 ms
    timer2.write_percent_channel(2, 75) // Canal 2 a los 750 ms

    // Habilitar interrupciones
    timer2.irq_enable()
    timer2.compare_irq_enable(timer2.compare_ch1)
    timer2.compare_irq_enable(timer2.compare_ch2)

    // Iniciar timer
    timer2.restart()
}
