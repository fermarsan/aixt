// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// Inicia una transacción SPI con configuraciones específicas.
@[as_macro]
pub fn start(freq any, bit_order any, mode any) {  
    C.SPI_BEGINTRANSACTION(C.SPISettings(freq, bit_order, mode))
}