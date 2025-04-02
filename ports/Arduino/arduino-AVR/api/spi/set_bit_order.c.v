// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// configures the bit order (lsbfirst or msbfirst).
@[as_macro]
pub fn set_bit_order(order u8) {  
    C.SPI_SETBITORDER(order)
}