// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Configura el divisor de frecuencia del reloj SPI.
@[as_macro]
pub fn set_clock_divider(divider u8) {  
    C.SPI_SETCLOCKDIVIDER(divider)
}