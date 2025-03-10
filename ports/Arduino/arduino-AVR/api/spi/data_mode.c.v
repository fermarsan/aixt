// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// data_mode configures the SPI data mode.
@[as_macro]
pub fn data_mode(mode u8) {  
    C.SPI_SETDATAMODE(mode)
}