// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_
//	- Fabián A. Rojas Acosta
//	- Alberto Pinzón Valero
//	- Fernando M. Santa
//
// _Date:_ 2024-2025
//
// ## Description
// Builtin definitions (Arduino Nano - ATmega328P port)
module main

#include "builtin.c"

fn C.pinMode(id u8, mode u8)
fn C.digitalWrite(id u8, val u8)
fn C.digitalRead(id u8) u8
fn C.digitalPinToPort(id u8)
fn C.digitalPinToBitMask(id u8)
fn C.portInputRegister(id u32)

pub const my_const = 45
