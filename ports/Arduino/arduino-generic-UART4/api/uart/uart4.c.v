// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart4

#include "uart4.c"

fn C.SERIAL4_BEGIN(baud_rate int)
fn C.SERIAL4_WRITE(character u8) 
fn C.SERIAL4_READ() u8
fn C.SERIAL4_READSTRING() string
fn C.SERIAL4_PRINT(message string)
fn C.SERIAL4_PRINTLN(message string)
fn C.SERIAL4_AVAILABLE() int

// setup function sets the data rate in bits per second (baud) for serial data transmission
@[as_macro]
pub fn setup(baud_rate int) {
	C.SERIAL4_BEGIN(baud_rate)
}

// any function gets the number of bytes (characters) available for reading
@[as_macro]
pub fn any() int {
	return C.SERIAL4_AVAILABLE()
}

// write function sends a single byte to the serial port
@[as_macro]
pub fn write(character u8) {  
	C.SERIAL4_WRITE(character)
}

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn print(message string) {  
	C.SERIAL4_PRINT(message)
}

// print function prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n')
@[as_macro]
pub fn println(message string) {  
	C.SERIAL4_PRINTLN(message)
}

// read function reads incoming serial data
@[as_macro]
pub fn read() u8 {
	return C.SERIAL4_READ()
}

// read function reads incoming serial data
@[as_macro]
pub fn read_string() string {
	return C.SERIAL4_READSTRING()
}