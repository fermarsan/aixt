// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart5

// Reads incoming serial data
@[inline]
pub fn read() u8 {
	return C.Serial.read()
}