// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// Inicializa el bus SPI.
@[as_macro]
pub fn setup() {  
    C.SPI_BEGIN()
}