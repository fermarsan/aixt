// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart1

// Sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.Serial.begin(baud_rate)
}