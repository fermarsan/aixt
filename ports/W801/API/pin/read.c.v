// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: READ functions (W801)
//              (PC port) 

module pin

//Reads the value from a specified digital pin, either HIGH or LOW
@[inline]
pub fn read(name int) int {
	return C.digitalRead(name)
}