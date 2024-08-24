// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_us functions (W801)
//              (PC port) 

module time

// sleep is a delay function in microseconds for the Aixt PC port. 
@[inline]
pub fn sleep_us(tus int) {
	C.delayMicroseconds(tus)
}