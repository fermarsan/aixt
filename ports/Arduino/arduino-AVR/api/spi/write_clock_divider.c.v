// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library

module spi

// clock_divider configures the SPI clock frequency divider.
@[as_macro]
pub fn write_clock_divider(divider u8) {  
    C.SPI_SETCLOCKDIVIDER(divider)
}