// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart3

#include "uart3.c"

fn C.SERIAL3_BEGIN(baud_rate int)
fn C.SERIAL3_WRITE(character u8) 
fn C.SERIAL3_READ() u8
fn C.SERIAL3_PRINT(message string)
fn C.SERIAL3_PRINTLN(message string)
fn C.SERIAL3_AVAILABLE() int
