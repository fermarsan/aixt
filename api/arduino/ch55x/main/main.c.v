//
// _Author:_
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026
//
// ## Description
// Builtin definitions (ch55x - ATmega328P port)
module main

#include "main.c"

fn C.pinMode(id u8, mode u8)
fn C.digitalWrite(id u8, val u8)
fn C.digitalRead(id u8) u8
