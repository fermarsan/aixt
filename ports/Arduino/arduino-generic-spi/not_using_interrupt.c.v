// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Deshabilita el uso de interrupciones en el bus SPI.
@[as_macro]
pub fn not_using_interrupt(interrupt_num u8) {  
    C.SPI_NOTUSINGINTERRUPT(interrupt_num)
}