// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// SPI


// FUNCTIONS DESCRIBED FOR THE SPI COMMUNICATION MODULE LIBRARY

#include <Arduino.h>
#include <SPI.h>
#include “spi.c”

fn C.SPI_BEGIN() // Initialize the SPI bus
fn C.SPI_END() // Close SPI bus
fn C.SPI_BEGINTRANSACTION(args ...any) // Initiate an SPI transaction
fn C.SPI_ENDTRANSACTION() // End an SPI transaction
fn C.SPI_TRANSFER(args ...any) u8 // Transfer a byte of data (send and receive simultaneously)
fn C.SPI_SETBITORDER(args ...any) // Set bit order (LSBFIRST or MSBFIRST)
fn C.SPI_SETDATAMODE(args ...any) // Set the data mode (SPI_MODE0, SPI_MODE1, etc.)
fn C.SPI_SETCLOCKDIVIDER(args ...any) // Configure clock frequency divider
fn C.SPI_USINGINTERRUPT(args ...any) // Enable use of interrupts
fn C.SPI_NOTUSINGINTERRUPT(args ...any) // Disable use of interrupts
fn C.SPI_ATTACHACHINTERRUPT(args ...any) //Perform the interrupt according to input
fn C.SPI_DETACHACHINTERRUPT() //Perform the interrupt according to input

pub const msb_1st = C.MSBFIRST
pub const lsb_1st = C.LSBFIRST

pub const neg_rising = C.SPI_MODE0
pub const neg_falling = C.SPI_MODE1
pub const pos_falling = C.SPI_MODE2
pub const pos_rising = C.SPI_MODE3

pub const clk_div_2 = C.SPI_CLOCK_DIV2
pub const clk_div_4 = C.SPI_CLOCK_DIV4
pub const clk_div_8 = C.SPI_CLOCK_DIV8
pub const clk_div_16 = C.SPI_CLOCK_DIV16
pub const clk_div_32 = C.SPI_CLO

Translated with DeepL.com (free version)