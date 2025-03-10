// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Inicia una transacción SPI con configuraciones específicas.
@[as_macro]
pub fn start(freq any, bit_order any, mode any) {  
    C.SPI_BEGINTRANSACTION(C.SPISettings(freq any, bit_order any, mode any))
}