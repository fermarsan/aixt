// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI


module spi

// Read and Write a byte buffer from SPI bus.
@[as_macro]
pub fn write(buffer u8[], n any) {  
    return C.SPI_TRANSFER(buffer, n)
}