// Project name: Aixt https://github.com/fermarsan/aixt.git
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

// Get the number of bytes (characters) available for reading from the serial port
@[inline]
pub fn any() int {
	return C.Serial2.available()
}