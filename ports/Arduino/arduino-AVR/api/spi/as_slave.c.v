// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

import pin {
    setup
}

// Inicializa el bus SPI.
@[as_macro]
pub fn as_slave() {
    C.SPI_BEGIN()
    C.SPCR |= (1 << (C.SPE)) // as a slave  
    pin.setup(spi.ss, pin.input) // SS as input
    pin.setup(spi.mosi, pin.input) // MOSI as input
    pin.setup(spi.miso, pin.output) // MISO as output
    pin.setup(spi.sck, pin.input) // SCK as input
}