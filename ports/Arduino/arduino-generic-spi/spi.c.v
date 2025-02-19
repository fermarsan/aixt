// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI

#include <SPI.h>
#include "spi.c"
#include <Arduino.h>

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
fn C.SPI_ATTACHINTERRUPT(args ...any) //Realiza la interrupción según entrada
