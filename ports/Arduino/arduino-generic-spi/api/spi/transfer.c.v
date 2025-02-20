// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI


module spi

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn transfer(data u8) u8 {  
    return C.SPI_TRANSFER(data)
}