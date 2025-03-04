// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart2

#include "uart2.c"

fn C.SERIAL2_BEGIN(baud_rate int)
fn C.SERIAL2_WRITE(character u8) 
fn C.SERIAL2_READ() u8
fn C.SERIAL2_PRINT(message string)
fn C.SERIAL2_PRINTLN(message string)
fn C.SERIAL2_AVAILABLE() int
