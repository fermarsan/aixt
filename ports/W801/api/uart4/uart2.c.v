// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart4

#include "uart4.c"

fn C.SERIAL4_BEGIN(baud_rate int)
fn C.SERIAL4_WRITE(character u8) 
fn C.SERIAL4_READ() u8
fn C.SERIAL4_PRINT(message string)
fn C.SERIAL4_PRINTLN(message string)
fn C.SERIAL4_AVAILABLE() int
