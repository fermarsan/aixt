// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: println.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

// Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[inline]
pub fn println(msg string) {
	C.printf('\033[1;32m')	// green
    C.printf('%s\n', msg)
}