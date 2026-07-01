//
// _Author:_
//	- Fernando M. Santa
//	- Fabián A. Rojas Acosta
//	- Alberto Pinzón Valero
// Date: 2024-2025
//
// ## Description
// Builtin definitions (Arduino Nano - ATmega328P port)
module main

#include "main.c"

fn C.pinMode(id u8, mode u8)
fn C.digitalWrite(id u8, val u8)
fn C.digitalRead(id u8) u8
fn C.digitalPinToPort(id u8)
fn C.digitalPinToBitMask(id u8)
fn C.portInputRegister(id u32)
