// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Functions for the SPI communication module library
module spi

#include "spi.h"

fn C.SPI_BEGIN() // Initialize the SPI bus
fn C.SPI_END() // Close SPI bus
fn C.SPI_BEGINTRANSACTION(args ...any) // Initiate an SPI transaction
fn C.SPI_ENDTRANSACTION() // End an SPI transaction
fn C.SPI_TRANSFER(args ...any) u8 // Transfer a byte of data (send and receive simultaneously)
fn C.SPI_TRANSFERBUFFER(args ...any) // Transfer a byte data buffer (send and receive simultaneously)
fn C.SPI_TRANSFER16(args ...any) u16 // Transfer a byte of data (send and receive simultaneously)
fn C.SPI_SETBITORDER(args ...any) // Set bit order (LSBFIRST or MSBFIRST)
fn C.SPI_SETDATAMODE(args ...any) // Set the data mode (SPI_MODE0, SPI_MODE1, etc.)
fn C.SPI_SETCLOCKDIVIDER(args ...any) // Configure clock frequency divider
fn C.SPI_USINGINTERRUPT(args ...any) // Enable use of interrupts
fn C.SPI_NOTUSINGINTERRUPT(args ...any) // Disable use of interrupts
fn C.SPI_ATTACHINTERRUPT(args ...any) //Perform the interrupt according to input
fn C.SPI_DETACHINTERRUPT() //Perform the interrupt according to input
fn C.SPISettings(args ...any) // Configure SPI settings

pub const ss	= u8(C.SS)
pub const miso	= u8(C.MISO)
pub const mosi	= u8(C.MOSI)
pub const sck  	= u8(C.SCK)

pub const msb_1st = u8(C.MSBFIRST)
pub const lsb_1st = u8(C.LSBFIRST)

pub const neg_rising  = u8(C.SPI_MODE0)
pub const neg_falling = u8(C.SPI_MODE1)
pub const pos_falling = u8(C.SPI_MODE2)
pub const pos_rising  = u8(C.SPI_MODE3)

// Inicializa el bus SPI.
@[as_macro]
pub fn as_master() {  
    // pin.setup(spi.ss, pin.output) // SS as output
    // pin.setup(spi.mosi, pin.output) // MOSI as output
    // pin.setup(spi.miso, pin.input) // MISO as input
    // pin.setup(spi.sck, pin.output) // SCK as output
    C.SPI_BEGIN()
}

// Inicializa el bus SPI.
@[as_macro]
pub fn as_slave() {
    C.SPI_BEGIN()
    C.SPCR |= (1 << (C.SPE)) // as a slave  
    pin.setup(spi.ss, pin.input) // SS as input
    pin.setup(spi.mosi, pin.input) // MOSI as input
    pin.setup(spi.miso, pin.output) // MISO as output
    pin.setup(spi.sck, pin.input) // SCK as input
}

// Finaliza el bus SPI.
@[as_macro]
pub fn end() {  
    C.SPI_END()
}

// irq_disable disables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)   
@[as_macro]
pub fn irq_disable() {
    // C.SPCR &= ~(1<<C.SPIE)	// Disable SPI Interrupt
    C.SPI_DETACHINTERRUPT()
}

// irq_enable enables and attaches the interrupt function for SPI via ISR (SPI_STC_vect)   
@[as_macro]
pub fn irq_enable() {
    // C.SPCR |= (1<<C.SPIE)   // Enable SPI Interrupt
    C.SPI_ATTACHINTERRUPT()
}

// Deshabilita el uso de interrupciones en el bus SPI.
@[as_macro]
pub fn using_irq(interrupt_num u8) {  
    C.SPI_NOTUSINGINTERRUPT(interrupt_num)
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn read() u8 {
    return C.SPI_TRANSFER(0x00)
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn read16() u16 {
    return C.SPI_TRANSFER16(0x0000)
}

// Read and Write a byte buffer from SPI bus.
@[as_macro]
pub fn rw_buffer(buffer []u8, n any) {  
    C.SPI_TRANSFERBUFFER(buffer, n)
}

// configures the bit order (lsbfirst or msbfirst).
@[as_macro]
pub fn set_bit_order(order u8) {  
    C.SPI_SETBITORDER(order)
}

// clock_divider configures the SPI clock frequency divider.
@[as_macro]
pub fn set_clock_divider(divider u8) {  
    C.SPI_SETCLOCKDIVIDER(divider)
}

// data_mode configures the SPI data mode.
@[as_macro]
pub fn set_mode(mode u8) {  
    C.SPI_SETDATAMODE(mode)
}

// Inicia una transacción SPI con configuraciones específicas.
@[as_macro]
pub fn start(freq any, bit_order any, mode any) {  
    C.SPI_BEGINTRANSACTION(C.SPISettings(freq, bit_order, mode))
}

// Finaliza una transacción SPI.
@[as_macro]
pub fn stop() {  
    C.SPI_ENDTRANSACTION()
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn transfer(data u8) u8 {  
    return C.SPI_TRANSFER(data)
}

// Transfiere 16 bits a través del bus SPI.
@[as_macro]
pub fn transfer16(data u16) u16 {  
    return C.SPI_TRANSFER16(data)
}

// Habilita el uso de interrupciones en el bus SPI.
@[as_macro]
pub fn using_irq(interrupt_num u8) {  
    C.SPI_USINGINTERRUPT(interrupt_num)
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn write(data u8) {  
    C.SPI_TRANSFER(data)
}

// Transfiere un byte de datos a través del bus SPI.
@[as_macro]
pub fn write16(data u16) {  
    C.SPI_TRANSFER16(data)
}