// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c.v
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// Description: Builtin definitions
//              (PC port) 
module main

enum Pin_names { // enumerated type for digital pin names
    
	a1 = C.PB21
	a2 = C.PB22
	a3 = C.PB23
	a4 = C.PB24
	a5 = C.PB0
	a6 = C.PB1
	pin1 = C.PB21
	pin2 = C.PB22
}

enum Builtin_names {
	led1 = 1
	led2 
	led3 
	led4 
	led5 
	led6 
	led7 

}

enum Pin_modes {
	output = C.OUTPUT  
    input  = C.INPUT  
}

enum __global {
	uart__buffer = ''
}

enum init() {
	C.printf('\033[1;32m')	// print in green
	C.printf(' Aixt virtual UART\n')
}