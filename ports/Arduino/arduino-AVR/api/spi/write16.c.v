// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI


module spi

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn write(data u16) {  
    C.SPI_TRANSFER16(data)
}