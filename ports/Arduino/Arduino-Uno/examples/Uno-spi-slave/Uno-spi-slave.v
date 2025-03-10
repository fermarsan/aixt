// slave.v

import spi
import pin
import uart
import time

// Define the pins
const push = u8(2) // Pin of the button
const led = u8(7) // LED pin

// Variables to store the received and sent state
__global ( 
    received = false
)

// Configuration function
fn setup() {
    // Initialize serial port
    uart.setup(115200)
    uart.println(“Initializing SPI slave...”)

    // Configure the pins
    pin.setup(push, pin.input) // Button pin as input
    pin.setup(led, pin.output) // Pin of the LED as output
    pin.setup(spi.miso, pin.output) // MISO pin as output

    // Initialize the SPI bus in slave mode
    spi.begin()
}

// Main loop function
fn loop() {
    // Check if data is available on SPI bus
    if spi.available() > 0 {
        // Read received byte
        slave_received = spi.transfer(0) // Dummy byte to receive data
        received = true
    }

    if received {
        // Control the LED according to the received data
        if slave_received == 1 {
            pin.write(led, pin.high) // Turn on the LED
        } else {
            pin.write(led, pin.low) // Turn off the LED
        }

        // Read button status
        button_value := pin.read(push)

        // Prepare the data to send
        if button_value == pin.high {
            slave_send = u8(1)
        } else {
            slave_send = u8(0)
        }

        // Send the data to the master
        spi.transfer(slave_send)

        // Reset the receive flag
        received = false
    }

    // Wait a brief moment before the next check.
    time.sleep_ms(100)
}

// Program entry point.
fn main() {
    setup()
    for {
        loop()
    }
}