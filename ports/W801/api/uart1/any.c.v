module uart// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: any.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart1


@[inline]
pub fn any() int {
	return C.Serial.available()
}