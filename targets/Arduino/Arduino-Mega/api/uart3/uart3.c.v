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

// Get the number of bytes (characters) available for reading from the serial port
@[inline]
pub fn any() int {
	return C.Serial3.available()
}

// Prints data to the serial port as human-readable ASCII text
@[inline]
pub fn print(message string) {
	C.Serial3.print(message)
}

// Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[inline]
pub fn println(message string) {
	C.Serial3.println(message)
}

// Reads incoming serial data
@[inline]
pub fn read() u8 {
	return C.Serial3.read()
}

// Reads incoming serial data
@[inline]
pub fn ready() u8 {
	return C.Serial3.ready()
}

// Sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.Serial3.begin(baud_rate)
}
