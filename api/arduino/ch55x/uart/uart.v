// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// UART module (ch55x boards)
module uart

fn C.USBSerial_begin(baud_rate int)
fn C.USBSerial_write(character u8)
fn C.USBSerial_read() u8
fn C.USBSerial_print(message string)
fn C.USBSerial_available() int

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[as_macro]
pub fn setup(baud_rate int) {
	C.USBSerial_begin(baud_rate)
}

// any function gets the number of bytes (characters) available for reading
@[as_macro]
pub fn any() int {
	return C.USBSerial_available()
}

// write function sends a single byte to the serial port
@[as_macro]
pub fn write(character u8) {
	C.USBSerial_write(character)
}

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn print(message string) {
	C.USBSerial_print(message)
}

// println function prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[as_macro]
pub fn println(message string) {
	C.USBSerial_print(message)
	C.USBSerial_write(13) // carriage return
	C.USBSerial_write(10) // newline
}

// read function reads incoming serial data
@[as_macro]
pub fn read() u8 {
	return C.USBSerial_read()
}
