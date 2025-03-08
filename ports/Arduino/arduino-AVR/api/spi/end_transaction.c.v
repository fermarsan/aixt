// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Finaliza una transacción SPI.
@[as_macro]
pub fn end_transaction() {  
    C.SPI_ENDTRANSACTION()
}