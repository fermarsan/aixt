// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI

// Functions for the SPI communication module library
module spi

// import pin {
//     setup
// }

// Inicializa el bus SPI.
@[as_macro]
pub fn as_master() {  
    // pin.setup(spi.ss, pin.output) // SS as output
    // pin.setup(spi.mosi, pin.output) // MOSI as output
    // pin.setup(spi.miso, pin.input) // MISO as input
    // pin.setup(spi.sck, pin.output) // SCK as output
    C.SPI_BEGIN()
}