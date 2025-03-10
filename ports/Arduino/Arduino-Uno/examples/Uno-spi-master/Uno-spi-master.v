// Project name: Blinking
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

// Define the pins
const push = u8(2) // Push button pin
const led = u8(7) // LED pin


// Initialize serial port
uart.setup(115200)
uart.print('Initializing SPI master...')

// Configure the pins
pin.setup(push, pin.input) // Button pin as input
pin.setup(led, pin.output) // Pin of the LED as output

// Initialize the SPI bus
spi.setup()
spi.clock_divider(8)    // Set clock frequency divider (SPI_CLOCK_DIV8)
pin.high(spi.ss) // disconnect the slave

for {
    send := pin.read(push)

    pin.low(spi.ss) // connect the slave

    // Read slave response
    response := spi.transfer(send) // Send a dummy byte to receive data

    // Control the LED depending on the slave's response
    if response == 1 {
        pin.high(led) // Turn on the LED
        uart.println('Master LED ON');
    } else {
        pin.low(led) // Turn off the LED
        uart.println('Master LED OFF');
    }

    // Wait for 1 second
    time.sleep_ms(1000)
}
