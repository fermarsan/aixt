// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// UART module (Arduino Nano - ATmega328P port)
module uart




fn C.uart_UartPutString(message string) 
fn C.uart_UartGetChar() u8
fn C.uart_Start()
fn C.uart_UartPutChar(character u8)









// fn C.SERIAL_BEGIN(baud_rate int)
// fn C.SERIAL_WRITE(character u8) 
// fn C.SERIAL_READ() u8
// fn C.SERIAL_READSTRING() string
// fn C.SERIAL_PRINT(message string)
// fn C.SERIAL_PRINTLN(message string)
// fn C.SERIAL_AVAILABLE() int