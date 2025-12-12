// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
//	- Fabián A. Rojas Acosta
//	- Alberto Pinzón Valero
//	- Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Builtin definitions (Arduino Nano - ATmega328P port)
module main

#include "builtin.c"

fn C.pinMode(id u8, mode u8) // uncomment if not included in api/builtin.c.v
fn C.digitalWrite(id u8, val u8) // uncomment if not included in api/builtin.c.v
fn C.digitalRead(id u8) u8
// fn C.DIGITAL_TOGGLE(id u8)
fn C.digitalPinToPort(id u8)
fn C.digitalPinToBitMask(id u8)
fn C.portInputRegister(id u32)