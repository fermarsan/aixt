// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Asignar una función de interrupción para SPI
@[as_macro]
pub fn attach_interrupt(handler fn()) {
    C.SPI_ATTACHINTERRUPT(handler)
}