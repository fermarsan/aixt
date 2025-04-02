// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library


module spi

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn write16(data u16) {  
    C.SPI_TRANSFER16(data)
}