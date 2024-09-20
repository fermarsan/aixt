// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: ready.c.v
// Authors:
//	- Johann Escobar Guzmán
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart2

// Reads incoming serial data
@[inline]
pub fn ready() u8 {
	return C.Serial.ready()
}