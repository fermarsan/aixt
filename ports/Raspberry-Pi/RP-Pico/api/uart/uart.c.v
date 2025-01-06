// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart

#include "uart.c"

fn C.SERIAL1_BEGIN(baud_rate int)
fn C.SERIAL1_WRITE(character u8) 
fn C.SERIAL1_READ() u8
fn C.SERIAL1_PRINT(message string)
fn C.SERIAL1_PRINTLN(message string)
fn C.SERIAL1_AVAILABLE() int
fn C.SERIAL1_PINS(tx_pin any, rx_pin any)
