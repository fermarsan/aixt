// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Configura el orden de los bits (LSBFIRST o MSBFIRST).
@[as_macro]
pub fn bit_order(order u8) {  
    C.SPI_SETBITORDER(order)
}