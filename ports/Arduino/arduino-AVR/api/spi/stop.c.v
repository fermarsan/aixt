// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// Finaliza una transacción SPI.
@[as_macro]
pub fn stop() {  
    C.SPI_ENDTRANSACTION()
}