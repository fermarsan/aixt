// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart5

#include "uart5.c"

fn C.SERIAL5_BEGIN(baud_rate int)
fn C.SERIAL5_WRITE(character u8) 
fn C.SERIAL5_READ() u8
fn C.SERIAL5_PRINT(message string)
fn C.SERIAL5_PRINTLN(message string)
fn C.SERIAL5_AVAILABLE() int
