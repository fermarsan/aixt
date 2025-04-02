// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// Functions for the SPI communication module library


module spi

// Read and Write a byte buffer from SPI bus.
@[as_macro]
pub fn rw_buffer(buffer []u8, n any) {  
    C.SPI_TRANSFERBUFFER(buffer, n)
}