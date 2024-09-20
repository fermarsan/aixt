// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: print.c.v
// Authors:
//	- Johann Escobar Guzmán
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart4

// Prints data to the serial port as human-readable ASCII text
@[inline]
pub fn print(message string) {  
	C.Serial.print(message)
}