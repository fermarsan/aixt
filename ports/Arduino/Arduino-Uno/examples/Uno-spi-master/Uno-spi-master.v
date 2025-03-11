// Project name: SPI communication between Arduino Uno boards
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Translated form: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
// Date: 10/03/2025
// Arduino-Uno board
module main

import spi
import pin
import uart
import time

const push = u8(2) // Push button pin
const led = u8(7) // LED pin

uart.setup(115200)          // Initialize serial port
uart.println('Initializing SPI master...')

pin.setup(push, pin.input)  // Button pin as input
pin.setup(led, pin.output)  // Pin of the LED as output

spi.as_master()             // Initialize the SPI bus as master
spi.set_clock_divider(8)    // Set clock frequency divider (SPI_CLOCK_DIV8)
spi.set_bit_order(spi.msb_1st)
spi.set_mode(spi.neg_rising)
pin.high(spi.ss)            // disconnect the slave

for {
    send := pin.read(push)

    pin.low(spi.ss)         // connect the slave
    // spi.start(16e6, spi.msb_1st, spi.neg_rising)
    spi.write(send)         // Send data to the slave
    response := spi.read()  // receive data
    // response := spi.transfer(send)
    pin.high(spi.ss)        // disconnect the slave
    // spi.stop()

    // Control the LED depending on the slave's response
    if response == 1 {
        pin.high(led) // Turn on the LED
        // uart.println('Master LED ON');
    } else {
        pin.low(led) // Turn off the LED
        // uart.println('Master LED OFF');
    }

    time.sleep_us(1)
}
