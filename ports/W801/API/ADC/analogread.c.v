// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: analogread.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: READ functions (W801)
//              (PC port) 

module adc

@[inline]
fn read(name int) int {
	return C.analogRead(name)
}