// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors: Fernando Martinez Santa 
// SPI


// Functions for the SPI communication module library


module spi

// Transfiere 16 bits a través del bus SPI.
@[as_macro]
pub fn transfer16(data u16) {  
    return C.SPI_TRANSFER16(data)
}