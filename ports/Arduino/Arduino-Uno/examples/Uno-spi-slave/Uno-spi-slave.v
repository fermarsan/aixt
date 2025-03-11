// Project name: SPI communication between Arduino Uno boards
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Translated form: https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial
// Date: 10/03/2025
// Arduino-Uno board
import spi
import pin
import uart
import time

const push = u8(2) // Pin of the button
const led = u8(7) // LED pin

__global ( 
    data_received = u8(0)
    received = false
)

@[spi_isr]  // Interrupt service routine for SPI
fn receive() {
    // Read received data
    // data_received = spi.read()
    data_received = u8(C.SPDR)
    received = true
}

uart.setup(115200)              // Initialize serial port
uart.println('Initializing SPI slave...')

pin.setup(push, pin.input)      // Button pin as input
pin.setup(led, pin.output)      // Pin of the LED as output
pin.setup(spi.miso, pin.output) // MISO pin as output

spi.as_slave()      // Initialize the SPI bus in slave mode
spi.set_bit_order(spi.msb_1st)
spi.set_mode(spi.neg_rising)
spi.irq_enable()    // enable SPI interrupt

for {
    if received {
        // Control the LED according to the received data
        if data_received == 1 {
            pin.high(led) // Turn on the LED
            uart.println('Slave LED ON')
        } else {
            pin.low(led) // Turn off the LED
            uart.println('Slave LED OFF')
        }

        button_value := pin.read(push)  // Read button status
        // spi.write(button_value) // Send the data to the master
        C.SPDR = button_value
        received = false    // Reset the receive flag
    }

    // time.sleep_ms(1)
}