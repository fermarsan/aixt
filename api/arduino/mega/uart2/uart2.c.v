// File: https://github.com/fermarsan/aixt/blob/main/
// Authors:
//	- Johann Escobar Guzmán
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
//
// // ## Description
// SLEEP_ms functions (W801)
//              (PC port)

module uart2

// any function gets the number of bytes (characters) available for reading from the serial port
@[inline]
pub fn any() int {
	return C.Serial2.available()
}

// print function prints data to the serial port as human-readable ASCII text
@[inline]
pub fn print(message string) {
	C.Serial2.print(message)
}

// println function prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[inline]
pub fn println(message string) {
	C.Serial2.println(message)
}

// read function reads incoming serial data
@[inline]
pub fn read() u8 {
	return C.Serial2.read()
}

// read function reads incoming serial data
@[inline]
pub fn ready() u8 {
	return C.Serial2.ready()
}

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[inline]
pub fn setup(baud_rate int) {
	C.Serial2.begin(baud_rate)
}
