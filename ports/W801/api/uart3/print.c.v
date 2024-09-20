// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	- Johann Escobar Guzmán
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart3

// Prints data to the serial port as human-readable ASCII text
@[inline]
pub fn print(message string) {  
	C.Serial3.print(message)
}