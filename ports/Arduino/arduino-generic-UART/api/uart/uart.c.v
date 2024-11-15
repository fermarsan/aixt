// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART module (Arduino Nano - ATmega328P port)
module uart

fn C.Serial.begin(baud_rate int)
fn C.Serial.write(character u8) 
fn C.Serial.read() u8
fn C.Serial.print(message string)
fn C.Serial.println(message string)
fn C.Serial.available() int