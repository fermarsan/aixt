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

module uart3

// Sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.Serial3.begin(baud_rate)
}