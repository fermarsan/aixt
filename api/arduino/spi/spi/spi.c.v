// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024 - 2025
// Description: SPI module.

module spi

// Functions for the SPI communication module library
#include <SPI.h>
#include "spi.c"

fn C.SPI_BEGIN() // Inicializar el bus SPI
fn C.SPI_END() // Cerrar el bus SPI
fn C.SPI_BEGINTRANSACTION(args ...any) // Iniciar una transacción SPI
fn C.SPI_ENDTRANSACTION() // Finalizar una transacción SPI
fn C.SPI_TRANSFER(args ...any) u8 // Transferir un byte de datos (envía y recibe simultáneamente)
fn C.SPI_SETBITORDER(args ...any) // Configurar el orden de los bits (LSBFIRST o MSBFIRST)
fn C.SPI_SETDATAMODE(args ...any) // Configurar el modo de datos (SPI_MODE0, SPI_MODE1, etc.)
fn C.SPI_SETCLOCKDIVIDER(args ...any) // Configurar el divisor de frecuencia del reloj
fn C.SPI_USINGINTERRUPT(args ...any) // Habilitar el uso de interrupciones
fn C.SPI_NOTUSINGINTERRUPT(args ...any) // Deshabilitar el uso de interrupciones
fn C.SERIAL_PRINT(data string) // Imprimir datos en el puerto serie

// Inicializa el bus SPI.
@[as_macro]
pub fn begin() {  
    C.SPI_BEGIN()
}

// Finaliza el bus SPI.
@[as_macro]
pub fn end() {  
    C.SPI_END()
}

// Inicia una transacción SPI con configuraciones específicas.
@[as_macro]
pub fn begin_transaction(settings SPISettings) {  
    C.SPI_BEGINTRANSACTION(settings)
}

// Finaliza una transacción SPI.
@[as_macro]
pub fn end_transaction() {  
    C.SPI_ENDTRANSACTION()
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn transfer(data u8) u8 {  
    return C.SPI_TRANSFER(data)
}

// Configura el orden de los bits (LSBFIRST o MSBFIRST).
@[as_macro]
pub fn set_bit_order(order u8) {  
    C.SPI_SETBITORDER(order)
}

// Configura el modo de datos SPI.
@[as_macro]
pub fn set_data_mode(mode u8) {  
    C.SPI_SETDATAMODE(mode)
}

// Configura el divisor de frecuencia del reloj SPI.
@[as_macro]
pub fn set_clock_divider(divider u8) {  
    C.SPI_SETCLOCKDIVIDER(divider)
}

// Habilita el uso de interrupciones en el bus SPI.
@[as_macro]
pub fn using_interrupt(interrupt_num u8) {  
    C.SPI_USINGINTERRUPT(interrupt_num)
}

// Deshabilita el uso de interrupciones en el bus SPI.
@[as_macro]
pub fn not_using_interrupt(interrupt_num u8) {  
    C.SPI_NOTUSINGINTERRUPT(interrupt_num)
}

// Imprime datos en el puerto serie.
@[as_macro]
pub fn print(data string) {  
    C.SERIAL_PRINT(data)
}