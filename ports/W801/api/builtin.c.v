// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	- Johann Escobar Guzmán 
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: Builtin definitions (W801 port) 
module main

enum Pin_names { // enumerated type for digital pin names
    
	a1 = C.PB21
	a2
	a3
	a4
	a5
	a6
	pin1 = C.PB21
	pin2
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
    input  = C.INPUT  
	output
}
