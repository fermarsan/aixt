// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_ms.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module time

// sleep is a delay function in milliseconds for the Aixt PC port. 
@[inline]
pub fn sleep_ms(tms int) {
	C.delay(tms)
}