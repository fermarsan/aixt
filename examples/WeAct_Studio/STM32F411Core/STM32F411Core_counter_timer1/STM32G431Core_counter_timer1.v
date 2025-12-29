// Project name: Timer Interrupt Test with Percent Compare (3 LEDs)
// Author: Fernando M. Santa & Santiago Farfán
// Date: 09/05/2025
// Board: STM32F411Coreboard

import timer1
import pin
import time

@[timer1_isr]
fn overflow_interrupt() {
    pin.high(pin.pa8)
    time.sleep_ms(200)
    pin.low(pin.pa8)
}

@[timer1_isr: 'timer1.compare_ch1']
fn compare_channel_1_interrupt() {
    pin.high(pin.pa9)
    time.sleep_ms(200)
    pin.low(pin.pa9)
}

@[timer1_isr: 'timer1.compare_ch2']
fn compare_channel_2_interrupt() {
    pin.high(pin.pa10)
    time.sleep_ms(200)
    pin.low(pin.pa10)
}

fn main() {
    //Configurar pines como salida
    pin.setup(pin.pa8, pin.output)   // Overflow (100%)
    pin.setup(pin.pa9, pin.output)   // Canal 1 (50%)
    pin.setup(pin.pa10, pin.output)  // Canal 2 (75%)

    // Configurar timer1 a 1 Hz (1 segundo por ciclo)
    timer1.setup(1, timer1.hz)

    // Especificar porcentaje en que se disparan los canales de comparación
    timer1.write_percent_channel(1, 50) // Canal 1 a los 500 ms
    timer1.write_percent_channel(2, 75) // Canal 2 a los 750 ms

    // Habilitar interrupciones
    timer1.irq_enable()
    timer1.compare_irq_enable(timer1.compare_ch1)
    timer1.compare_irq_enable(timer1.compare_ch2)

    // Iniciar timer
    timer1.restart()
}