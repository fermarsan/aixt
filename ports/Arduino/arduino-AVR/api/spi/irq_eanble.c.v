// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the spi communication module library

module spi

// irq_enable enables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)   
@[as_macro]
pub fn irq_enable() {
    // C.SPCR |= (1<<C.SPIE)   // Enable SPI Interrupt
    C.SPI_ATTACHINTERRUPT()
}