// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

module spi

// Asignar una función de interrupción para SPI
@[as_macro]
pub fn irq_enable() {
    C.SPI_ATTACHINTERRUPT()
    // C.SPI_USINGINTERRUPT(interrupt_num)
}