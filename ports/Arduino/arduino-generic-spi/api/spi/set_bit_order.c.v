// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Configura el orden de los bits (LSBFIRST o MSBFIRST).
@[as_macro]
pub fn set_bit_order(order u8) {  
    C.SPI_SETBITORDER(order)
}