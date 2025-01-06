// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: usb_uart module (Arduino Nano - ATmega328P port)
module usb_uart

#include "usb_uart.c"

fn C.SERIAL_BEGIN(baud_rate int)
fn C.SERIAL_WRITE(character u8) 
fn C.SERIAL_READ() u8
fn C.SERIAL_PRINT(message string)
fn C.SERIAL_PRINTLN(message string)
fn C.SERIAL_AVAILABLE() int

