// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Inicia una transacción SPI con configuraciones específicas.
@[as_macro]
pub fn begin_transaction(settings SPISettings) {  
    C.SPI_BEGINTRANSACTION(settings)
}