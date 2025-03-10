// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the spi communication module library

module spi

// irq_disable disables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)   
@[as_macro]
pub fn irq_disable() {
    // C.SPCR &= ~(1<<C.SPIE)	// Disable SPI Interrupt
    C.SPI_DETACHINTERRUPT()
}
