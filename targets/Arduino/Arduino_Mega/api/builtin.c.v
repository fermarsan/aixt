// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Builtin definitions (Arduino Mega - ATmega2560 port)
module main

#include "builtin.c"

fn C.pinMode(id u8, mode u8) 
fn C.digitalWrite(id u8, val u8) 
fn C.digitalRead(id u8) u8
fn C.digitalPinToPort(id u8)
fn C.digitalPinToBitMask(id u8)
fn C.portInputRegister(id u32)