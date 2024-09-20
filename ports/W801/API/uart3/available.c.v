// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: available.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart3

// Get the number of bytes (characters) available for reading from the serial port
@[inline]
pub fn any() int {
	return C.Serial.available()
}